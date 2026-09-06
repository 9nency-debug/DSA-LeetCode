class Solution {
public:
    int numDistinct(string s, string t) {
        using ll = long long;
        int m = s.length(), n = t.length();
        vector<ll> dp(n + 1, 0);
        dp[n] = 1;
        for(int i=m - 1; i>= 0; i--) {
            int diag = dp[n];
            for(int j =n-1; j >= 0; j--) {
                int old = dp[j];
                if(s[i] == t[j]) {
                    dp[j] = dp[j] + diag;
                }
                diag = old;
            }
        }
        return dp[0];
    }
};