class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> target(n);
        iota(target.begin(), target.end(), 0);
        if (nums == target) return 0;
        int type = -1, k = -1;
        bool asc = true, desc = true;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != (nums[0] + i) % n)
                asc = false;
            if (nums[i] != (nums[0] - i + n) % n)
                desc = false;
        }
        if(asc) {
            type = 0;
            k = nums[0];
        } else if (desc) {
            type = 1;
            k = (nums[0] + 1) % n;
        } else {
            return -1;
        }
        vector<vector<int>> dist(2, vector<int>(n, -1));
        queue<pair<int, int>> q;
        dist[type][k] = 0;
        q.push({type, k});
        while (!q.empty()) {
            auto [t, x] = q.front();
            q.pop();
            if (t == 0 && x == 0) return dist[t][x];
            int nt = 1 - t, nx = x;
            if (dist[nt][nx] == -1) {
                dist[nt][nx] = dist[t][x] + 1;
                q.push({nt, nx});
            }
            nt = t;
            nx = (t == 0) ? (x + 1) % n : (x - 1 + n) % n;

            if (dist[nt][nx] == -1) {
                dist[nt][nx] = dist[t][x] + 1;
                q.push({nt, nx});
            }
        }
        return -1;
    }
};
