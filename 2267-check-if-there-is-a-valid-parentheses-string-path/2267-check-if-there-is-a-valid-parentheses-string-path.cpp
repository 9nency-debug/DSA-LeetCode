// // // class Solution {
// // // public:
// // //     bool hasValidPath(vector<vector<char>>& A) {
// // //         int m = A.size(), n = A[0].size();
// // //         bool dp[m + 1][n + 1][103] = {};
// // //         dp[0][0][1] = true;
// // //         for (int i = 0; i < m; i++) {
// // //             for (int j = 0; j < n; j++) {
// // //                 for (int k = 1; k <= 101; k++) {
// // //                     int next = k + (A[i][j] == '(' ? -1 : 1);
// // //                     dp[i][j + 1][k] |= dp[i][j][next];
// // //                     dp[i + 1][j][k] |= dp[i][j][next];
// // //                 }
// // //             }
// // //         }
// // //         return dp[m][n - 1][1];
// // //     }
// // // };

// // class Solution {
// // public:
// //     bool hasValidPath(vector<vector<char>>& A) {
// //         int m = A.size(), n = A[0].size();

// //         vector<vector<vector<bool>>> dp(m + 1,vector<vector<bool>>(n + 1, vector<bool>(103, false)));
// //         dp[0][0][1] = true;
// //         for (int i = 0; i < m; i++) {
// //             for (int j = 0; j < n; j++) {
// //                 for (int k = 1; k <= 101; k++) {
// //                     if (!dp[i][j][k]) continue;
// //                     int next = k + (A[i][j] == '(' ? -1 : 1);
// //                     if (next < 0 || next >= 103) continue;
// //                     dp[i][j + 1][next] = true;
// //                     dp[i + 1][j][next] = true;
// //                 }
// //             }
// //         }
// //         return dp[m][n - 1][1];
// //     }
// // };

// class Solution {
// public:
//     bool hasValidPath(vector<vector<char>>& A) {
//         int m = A.size();
//         int n = A[0].size();

//         vector<vector<vector<bool>>> dp(
//             m,
//             vector<vector<bool>>(n, vector<bool>(m + n + 2, false))
//         );

//         dp[0][0][1] = true;

//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 for (int k = 1; k <= m + n; k++) {

//                     if (!dp[i][j][k])
//                         continue;

//                     int next;

//                     if (A[i][j] == '(')
//                         next = k + 1;
//                     else
//                         next = k - 1;

//                     if (next < 1)
//                         continue;
//                     if (i + 1 < m)
//                         dp[i + 1][j][next] = true;
//                     if (j + 1 < n)
//                         dp[i][j + 1][next] = true;
//                 }
//             }
//         }
//         return dp[m - 1][n - 1][1];
//     }
// };

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        int dx[] = {1, 0};
        int dy[] = {0, 1};
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;
        vector<vector<vector<int>>> vis(m, vector<vector<int>>(n, vector<int>(m + n, 0)));
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1});
        vis[0][0][1] = 1;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int r = p.first.first;
            int c = p.first.second;
            int cnt = p.second;
            if (r == m - 1 && c == n - 1 && cnt == 0)
                return true;
            for (int k = 0; k < 2; k++) {
                int nr = dx[k] + r;
                int nc = dy[k] + c;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int newcnt = cnt;
                    if (grid[nr][nc] == '(')
                        newcnt++;
                    else
                        newcnt--;
                    if (newcnt < 0)
                        continue;
                    if (!vis[nr][nc][newcnt]) {
                        vis[nr][nc][newcnt] = 1;
                        q.push({{nr, nc}, newcnt});
                    }
                }
            }
        }
        return false;
    }
};