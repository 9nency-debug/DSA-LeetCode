class DSU{
private:
    vector<int>par,sze;

public:
    DSU(int n){
        par.resize(n+1);
        sze.resize(n+1,1);
        iota(par.begin(),par.end(),0);
    }
    int find(int x){
        if(x==par[x]) return x;
        return par[x]=find(par[x]);
    }
    void unite(int x, int y){
        x=find(x);
        y=find(y);
        if(x==y) return ;
        if(sze[x]<sze[y]){
            swap(x,y);
        }
        par[y]=x;
        sze[x]+=sze[y];
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int q=queries.size();
        vector<bool>ans(q);
        DSU ds(n+1);
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]<=maxDiff){
                ds.unite(i,i-1);
            }
        }
        for(int i=0;i<q;i++){
            if(ds.find(queries[i][0])==ds.find(queries[i][1])){
                ans[i]=true;
            }
        }
        return ans;
    }
};
