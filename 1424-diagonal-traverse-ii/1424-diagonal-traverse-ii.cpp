class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> diag[200001];
        int maxDiagonal = 0;
        // Store elements according to their diagonal (i + j)
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                diag[i + j].push_back(nums[i][j]);
                maxDiagonal = max(maxDiagonal, i + j);
            }
        }
        vector<int> ans;
        // Traverse each diagonal in reverse
        for (int d = 0; d <= maxDiagonal; d++) {
            for (int i = diag[d].size() - 1; i >= 0; i--) {
                ans.push_back(diag[d][i]);
            }
        }
        return ans;
    }
};