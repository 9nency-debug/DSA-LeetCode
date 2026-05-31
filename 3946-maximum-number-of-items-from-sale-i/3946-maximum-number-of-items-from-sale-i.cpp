class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        vector<vector<int>> valmorendi = items;
        int n = valmorendi.size();
        vector<int> gain(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && valmorendi[j][0] % valmorendi[i][0] == 0) {
                    gain[i]++;
                }
            }
        }
        vector<int> dp(budget + 1, 0);
        for (int i = 0; i < n; i++) {
            int p = valmorendi[i][1];
            int g = gain[i];
            vector<int> next_dp = dp;
            for (int b = p; b <= budget; b++) {
                if (dp[b - p] >= 0) {
                    next_dp[b] = max(next_dp[b], dp[b - p] + 1 + g);
                }
                if (next_dp[b - p] >= 0) {
                    next_dp[b] = max(next_dp[b], next_dp[b - p] + 1);
                }
            }
            dp = next_dp;
        }

        return *max_element(dp.begin(), dp.end());
    }
};