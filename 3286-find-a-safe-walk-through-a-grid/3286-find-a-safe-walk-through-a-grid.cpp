class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int currHealth = health - grid[0][0];
        if (currHealth < 1) {
            return false;
        }
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<tuple<int, int, int>> pq;
        pq.push({currHealth, 0, 0});
        vector<vector<int>> mem(m, vector<int>(n, 0));
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        mem[0][0] = currHealth;
        vis[0][0] = true;
        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!pq.empty()) {
            auto [h, x, y] = pq.top();
            pq.pop();
            for (int i = 0; i < 4; i++) {
                int u = x + dir[i][0];
                int v = y + dir[i][1];
                if (u >= 0 && v >= 0 && u < m && v < n) {
                    currHealth = h - grid[u][v];
                    if (u == m - 1 && v == n - 1 && currHealth >= 1) {
                        return true;
                    }
                    if (!vis[u][v] || currHealth > mem[u][v]) {
                        mem[u][v] = currHealth;
                        vis[u][v] = true;
                        pq.push({currHealth, u, v});
                    }
                }
            }
        }
        return false;
    }
};