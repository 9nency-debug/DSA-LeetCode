class Solution {
public:
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int> adj(n, 0);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u] |= (1 << v);
            adj[v] |= (1 << u);
        }
        
        int ans = 0;
        int total = 1 << n;
        for (int mask = 1; mask < total; mask++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) sum += nums[i];
            }
            
            if (sum % 2) 
                continue;
            int start = __builtin_ctz(mask);
            int vis = 0;
            queue<int> q;
            q.push(start);
            vis |= (1 << start);
            
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                int nei = adj[u] & mask;
                while (nei) {
                    int v = __builtin_ctz(nei);
                    nei &= (nei - 1);
                    if (!(vis & (1 << v))) {
                        vis |= (1 << v);
                        q.push(v);
                    }
                }
            }
            
            if (vis == mask) 
                ans++;
        }
        
        return ans;
    }
};