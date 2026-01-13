class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e18, high = -1e18;
        
        for (auto &s : squares) {
            low = min(low, (double)s[1]);
            high = max(high, (double)(s[1] + s[2]));
        }
        
        for (int iter = 0; iter < 100; iter++) { // precision control
            double mid = (low + high) / 2.0;
            double below = 0, above = 0;
            
            for (auto &s : squares) {
                double y = s[1], side = s[2];
                double top = y + side;
                double area = side * side;
                
                if (top <= mid) {
                    below += area;
                } 
                else if (y >= mid) {
                    above += area;
                } 
                else {
                    double belowHeight = mid - y;
                    double aboveHeight = top - mid;
                    below += belowHeight * side;
                    above += aboveHeight * side;
                }
            }
            
            if (below < above)
                low = mid;
            else
                high = mid;
        }
        
        return low;
    }
};
