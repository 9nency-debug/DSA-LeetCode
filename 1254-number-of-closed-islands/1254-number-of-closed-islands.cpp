class Solution {
public:
    int n, m;
    bool isValid(int i, int j){
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    bool bfs(int i, int j, vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 1;
        bool ans = true;
        int rows[4] = {1, 0, -1, 0};
        int cols[4] = {0, 1, 0, -1};
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for(int k = 0; k < 4; k++) {
                int nr = r + rows[k];
                int nc = c + cols[k];
                if (!isValid(nr, nc)) ans = false;
                else if (grid[nr][nc] == 0) {
                    grid[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
        return ans;
    }
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    if (bfs(i, j, grid)) {
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};
