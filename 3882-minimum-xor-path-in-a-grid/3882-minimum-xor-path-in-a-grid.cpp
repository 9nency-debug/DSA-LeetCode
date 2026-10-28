class Solution {
public:
    int minVal = INT_MAX;
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        minVal = INT_MAX;
        vector<vector<vector<bool>>> dp(m,vector<vector<bool>>(n,vector<bool>(1024, false)
            )
        );
        rec(grid, 0, 0, 0, dp);
        return minVal;
    }
    void rec(
        vector<vector<int>>& grid,
        int i,
        int j,
        int curr,
        vector<vector<vector<bool>>>& dp
    ){
        int m = grid.size();
        int n = grid[0].size();
        if(i >= m || j >= n) {
            return;
        }
        if(i == m - 1 && j == n - 1) {
            minVal = min(minVal, curr ^ grid[i][j]);
            return;
        }
        if(dp[i][j][curr]) {
            return;
        }
        dp[i][j][curr] = true;
        int nextXor = curr ^ grid[i][j];
        rec(grid, i, j + 1, nextXor, dp);
        rec(grid, i + 1, j, nextXor, dp);
    }
};