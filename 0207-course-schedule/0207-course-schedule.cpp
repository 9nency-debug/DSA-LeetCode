class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //kahn's Algo (topological sorting) -> BFS algo => directed grf
        vector<int>adj[numCourses];
        vector<int>in(numCourses,0);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
            in[it[0]]++;
        } 
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(in[i]==0) q.push(i);
        }
        int cnt=0; //Courses Done
        while(!q.empty()){
            int x=q.front();
            q.pop();
            cnt++;
            for(auto it:adj[x]){ 
                in[it]--; //Removing edges
                if(in[it]==0) q.push(it);
            }
        }
        //All Done => No cycle
        return cnt==numCourses;
    }
};