
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Kahn's Algo (Topological Sorting) -> BFS -> Directed graph
        vector<int> adj[numCourses];
        vector<int> in(numCourses, 0);
        for(auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
            in[it[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(in[i] == 0) q.push(i);
        }
        vector<int> ans; //Stores course ordering
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            ans.push_back(x);
            for(auto it : adj[x]) {
                in[it]--; //Removing edges
                if(in[it] == 0) q.push(it);
            }
        }
        // All courses done => No cycle
        if(ans.size() == numCourses) return ans;
        return {}; //cycle exist
    }
};
