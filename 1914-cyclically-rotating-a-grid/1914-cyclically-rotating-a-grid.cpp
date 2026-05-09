class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int i=grid.size(),j=grid[0].size(),cnt=0;
        while(i>0&&j>0){
            cnt++;
            i-=2;
            j-=2;
        }
        int left=0,right=grid[0].size()-1,top=0,bottom=grid.size()-1;
        while(left<right&&top<bottom){
            vector<int>vec;
            for(int i=left;i<=right;i++){
                vec.push_back(grid[left][i]);
            }
            for(int i=top+1;i<=bottom;i++){
                vec.push_back(grid[i][right]);
            }
            for(int i=right-1;i>=left;i--){
                vec.push_back(grid[bottom][i]);
            }
            for(int i=bottom-1;i>top;i--){
                vec.push_back(grid[i][left]);
            }
            int x=k%vec.size();
            reverse(vec.begin(),vec.begin()+x);
            reverse(vec.begin()+x,vec.end());
            reverse(vec.begin(),vec.end());
            int a=0;
            for(int i=left;i<=right;i++){
                grid[left][i]=vec[a];
                a++;
            }
            for(int i=top+1;i<=bottom;i++){
                grid[i][right]=vec[a];
                a++;
            }
            for(int i=right-1;i>=left;i--){
                grid[bottom][i]=vec[a];
                a++;
            }
            for(int i=bottom-1;i>top;i--){
                grid[i][left]=vec[a];
                a++;
            }
            top++;
            bottom--;
            left++;
            right--;
        }
        return grid;
    }
};