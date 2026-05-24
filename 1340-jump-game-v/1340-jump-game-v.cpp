class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, 1);
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({arr[i], i});
        }
        sort(v.begin(), v.end());
        int ans = 1;
        for(auto &[val, i] : v) {
            for(int j = i - 1; j >= max(0, i - d); j--) {
                if(arr[j] >= arr[i])
                    break;
                dp[i] = max(dp[i], 1 + dp[j]);
            }
            for(int j = i + 1; j <= min(n - 1, i + d); j++) {
                if(arr[j] >= arr[i])
                    break;
                dp[i] = max(dp[i], 1 + dp[j]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};