class Solution {
public:
    int path(vector<vector<int>>& abc,vector<vector<int>>& mat,int i,int j,int n,int m,int val){
        if(i==-1 || j==-1 || i==n || j==m){
            return 0;
        }
        if(mat[i][j]<=val){
            return 0;
        }
        if(abc[i][j]!=-1){
            return abc[i][j];
        }
        int a = path(abc,mat,i-1,j,n,m,mat[i][j]);
        int b = path(abc,mat,i,j-1,n,m,mat[i][j]);
        int c = path(abc,mat,i+1,j,n,m,mat[i][j]);
        int d = path(abc,mat,i,j+1,n,m,mat[i][j]);
        if(a>b && a>c && a>d){
            abc[i][j]=a+1;
        }
        else if(b>c && b>d){
            abc[i][j]=b+1;
        }
        else if(c>d){
            abc[i][j]=c+1;
        } else {
            abc[i][j]=d+1;
        }
        return abc[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int max=0;
        vector<vector<int>> abc(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                abc[i].push_back(-1);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int z = path(abc,mat,i,j,n,m,-1);
                if(z>max){
                    max=z;
                }
            }
        }
        return max;
    }
};