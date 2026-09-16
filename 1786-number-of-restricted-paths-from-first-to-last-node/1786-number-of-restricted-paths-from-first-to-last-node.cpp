class Solution {
public:
    int dp[20010];
    int mod=1e9+7;
    int dfs(int node,int n,vector<vector<pair<int,int>>> &g,vector<long long> &dist){
        if(node==1) return 1;
        if(dp[node]!=-1) return dp[node];

        int ans=0;
        for(auto it:g[node]){
            int child=it.first;
            if(dist[child]>dist[node]) ans=(ans+dfs(child,n,g,dist)%mod)%mod;
        }
        return dp[node]=ans%mod;
    }

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> g(n+1);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<long long> dist(n+1,1e18);
        pq.push({0,n});
        dist[n]=0;
        while(!pq.empty()){
            auto v=pq.top();pq.pop();
            int node=v[1];
            int d=v[0];
            if (d > dist[node]) continue;
            for(auto it:g[node]){
                int child=it.first;
                int w=it.second;
                if(d+w<dist[child]){
                    dist[child]=d+w;
                    pq.push({d+w,child});
                }
            }
        }
        memset(dp,-1,sizeof(dp));
        return dfs(n,n,g,dist);
    }
};

