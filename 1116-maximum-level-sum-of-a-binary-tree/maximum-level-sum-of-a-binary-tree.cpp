/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int res=-1;
        int lvl=1;
         int ans =INT_MIN;
        while(!q.empty()){
            int s = q.size();
            int ksum = 0;
            for(int i=0;i<s;i++){
                TreeNode* front = q.front();
                q.pop();

                ksum+=front->val;

                if(front->left){
                    q.push(front->left);
                }

                if(front->right){
                    q.push(front->right);
                }
            }
            if(ans<ksum){
               ans=ksum;
               res=lvl;
            }
            lvl++;
        }
        return res;
    }
};