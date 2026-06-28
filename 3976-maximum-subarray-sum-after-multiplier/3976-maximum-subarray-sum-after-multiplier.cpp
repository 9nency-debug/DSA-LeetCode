class Solution {
public:
    using ll=long long;
    ll n,k,mode;
    vector<ll>A;
    vector<vector<ll>>dp;
    ll op(ll x){
        if(mode==0)
            return x*k;
        return x/k;
    }
    ll f(int i,int st){
        if(i==0){
            if(st==0)
                return A[0];
            if(st==1)
                return op(A[0]);
            return -1e16;
        }
        ll&ret=dp[i][st];
        if(ret!=-1e16)
            return ret;
        ll x=A[i],y=op(x);
        if(st==0)
            ret=max(x,x+f(i-1,0));
        else if(st==1)
            ret=max({y,y+f(i-1,0),y+f(i-1,1)});
        else
            ret=max(x+f(i-1,1),x+f(i-1,2));
        return ret;
    }
    ll solve(){
        dp.assign(n,vector<ll>(3,-1e16));
        ll res=-1e16;
        for(int i=0;i<n;++i){
            res=max(res,f(i,0));
            res=max(res,f(i,1));
            res=max(res,f(i,2));
        }
        return res;
    }
    ll maxSubarraySum(vector<int>&nums,int _k) {
        n=nums.size(),mode=0,k=_k;
        A.resize(n);
        for(int i=0;i<n;++i)
            A[i]=nums[i];
        ll res=solve();
        mode=1;
        res=max(res,solve());
        return res;
    }
};