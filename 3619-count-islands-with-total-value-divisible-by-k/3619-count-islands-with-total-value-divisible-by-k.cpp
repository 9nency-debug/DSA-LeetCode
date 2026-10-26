class Solution {
public:
vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
bool Help(vector<vector<int>> &grid,vector<vector<int>> &vis,int x,int y,int n,int m,int k){
    queue<pair<int,int>> q;
    q.push({x,y});
    vis[x][y] = 1;
    long long total = 0;
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        int nx = p.first;
        int ny = p.second;
        total += grid[nx][ny];
        for(int i = 0;i<4;i++){
            int newx = nx+dir[i][0];
            int newy = ny+dir[i][1];
            if(newx>=0 && newx<n && newy>=0 && newy<m && 
            grid[newx][newy] != 0 && !vis[newx][newy] ){
                q.push({newx,newy});
                vis[newx][newy] = 1;
            }
        }
    }
    return total%k == 0?1:0;
}
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j] != 0){
                    if(Help(grid,vis,i,j,n,m,k)){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};