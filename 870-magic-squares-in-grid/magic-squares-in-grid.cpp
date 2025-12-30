class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {

                // center must be 5
                if (grid[i+1][j+1] != 5)
                    continue;

                vector<bool> seen(10, false);
                bool valid = true;

                // check numbers 1 to 9 and distinct
                for (int r = i; r < i + 3; r++) {
                    for (int c = j; c < j + 3; c++) {
                        int val = grid[r][c];
                        if (val < 1 || val > 9 || seen[val]) {
                            valid = false;
                            break;
                        }
                        seen[val] = true;
                    }
                }

                if (!valid) continue;

                int s = grid[i][j] + grid[i][j+1] + grid[i][j+2];

                // rows
                for (int r = 0; r < 3; r++) {
                    if (grid[i+r][j] + grid[i+r][j+1] + grid[i+r][j+2] != s)
                        valid = false;
                }

                // columns
                for (int c = 0; c < 3; c++) {
                    if (grid[i][j+c] + grid[i+1][j+c] + grid[i+2][j+c] != s)
                        valid = false;
                }

                // diagonals
                if (grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2] != s)
                    valid = false;

                if (grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j] != s)
                    valid = false;

                if (valid)
                    count++;
            }
        }
        return count;
    }
};
