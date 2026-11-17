class Solution {
public:
    int n;
    const int INF = 1e9;
    vector<vector<int>> cost, memo;
    int getCost(string& s, int l, int r) {
        int len = r - l + 1;
        int best = INF;
        for (int d = 1; d < len; d++) {
            if (len % d != 0) continue;
            int changes = 0;
            for (int offset = 0; offset < d; offset++) {
                int left = l + offset;
                int right = r - d + 1 + offset;
                while (left < right) {
                    if (s[left] != s[right])
                        changes++;
                    left += d;
                    right -= d;
                }
            }
            best = min(best, changes);
        }
        return best;
    }
    int dfs(int start, int k) {
        if (k == 0)
            return start == n ? 0 : INF;
        if (n - start < 2 * k)
            return INF;
        if (memo[start][k] != -1)
            return memo[start][k];
        int ans = INF;
        for (int end = start + 2; end <= n - 2 * (k - 1); end++) {
            ans = min(ans, cost[start][end - 1] + dfs(end, k - 1));
        }
        return memo[start][k] = ans;
    }
    int minimumChanges(string s, int k) {
        n = s.size();
        cost.assign(n, vector<int>(n, 0));
        memo.assign(n, vector<int>(k + 1, -1));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                cost[i][j] = getCost(s, i, j);
            }
        }
        return dfs(0, k);
    }
};