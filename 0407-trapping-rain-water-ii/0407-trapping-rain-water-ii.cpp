#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        if (m <= 2 || n <= 2) 
        return 0;

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>> pq;

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], {i,0}});
            pq.push({heightMap[i][n-1], {i,n-1}});
            vis[i][0] = vis[i][n-1] = true;
        }

        for (int j = 1; j < n-1; j++) {
            pq.push({heightMap[0][j], {0,j}});
            pq.push({heightMap[m-1][j], {m-1,j}});
            vis[0][j] = vis[m-1][j] = true;
        }

        int ans = 0;
        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int h = top.first;
            int x = top.second.first;
            int y = top.second.second;

            for (auto &d : dir) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n || vis[nx][ny])
                    continue;

                vis[nx][ny] = true;

                if (heightMap[nx][ny] < h)
                    ans += h - heightMap[nx][ny];

                pq.push({max(h, heightMap[nx][ny]), {nx, ny}});
            }
        }

        return ans;
    }
};