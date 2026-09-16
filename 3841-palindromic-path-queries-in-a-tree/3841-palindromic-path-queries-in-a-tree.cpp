#define ll long long
const ll MAXN=1e5+5;
class Solution {
public:
vector<ll> g[MAXN];
ll parent[MAXN];
ll sz[MAXN];
ll heavy[MAXN];
ll tree[4*MAXN+5];
ll head[MAXN];
ll v[MAXN];
ll depth[MAXN];
ll pos[MAXN];
ll cur=1;
ll arr[MAXN];
void dfs1(ll node,ll p,ll d){
    sz[node]=1;
    heavy[node]=-1;
    parent[node]=p;
    depth[node]=d;
    ll mx=0;
    for(auto it:g[node]){
        if(it!=p){
            dfs1(it,node,d+1);
            sz[node]+=sz[it];
            if(sz[it]>mx){
                mx=sz[it];
                heavy[node]=it;
            }
        }
    }
}
void dfs2(ll node,ll p,ll h){
    head[node]=h;
    pos[node]=cur++;
    if(heavy[node]!=-1){
      dfs2(heavy[node],node,h);
    }
    for(auto it:g[node]){
        if(it!=p && it!=heavy[node]){
            dfs2(it,node,it);
        }
    }
}
void map_values(ll n){
    for(ll i=0;i<n;i++){
        arr[pos[i]]=v[i];
    }
    
}
void build(ll node,ll l,ll r){
    if(l==r){
        tree[node]=(1ll<<arr[l]);
        return;
    }
    ll mid=l+(r-l)/2;
    build(2*node+1,l,mid);
    build(2*node+2,mid+1,r);

        tree[node]=tree[2*node+1]^tree[2*node+2];
    

}
void update(ll node,ll l,ll r,ll ind,ll val,ll prev){
  if(l==r){
    tree[node]=tree[node]^(1ll<<prev);
    tree[node]=tree[node]^(1ll<<val);

    return;

  }
  ll mid=l+(r-l)/2;
  if(ind<=mid){
    update(2*node+1,l,mid,ind,val,prev);

  }
  else{
    update(2*node+2,mid+1,r,ind,val,prev);

  }
 tree[node]=tree[2*node+1]^tree[2*node+2];
}
ll query(ll node,ll start,ll end,ll l,ll r){
    if(l>end || r<start){
  
        return 0;
    }
    if(l>=start && r<=end){
        return tree[node];
    }
    ll mid=l+(r-l)/2;
    ll res=query(2*node+1,start,end,l,mid)^query(2*node+2,start,end,mid+1,r);
    return res;
}
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        cur=0;
        for(ll i=0;i<n;i++){
            v[i]=s[i]-'a';
            g[i].clear();
            tree[i]=0;

        }
        for(auto e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);

        }
        dfs1(0,-1,0);
        dfs2(0,-1,0);
        map_values(n);
        build(0,0,n-1);
        vector<bool> aa;
        for(auto q:queries){
            stringstream ss(q);
            ll t=0;
            ll node;
            ll nc=-1;
            vector<string> s;
            string word;
            while (ss >> word) {
    s.push_back(word);
}
            if(s[0]=="update"){
                node=stoi(s[1]);
                char sss=s[2][0];
                nc=sss-'a';
                update(0,0,n-1,pos[node],nc,v[node]);
                v[node]=nc;
            } else {
                ll x=stoi(s[1]);
                ll y=stoi(s[2]);
                bool ans=true;
                ll pali=0;
                ll len=0;
                while(head[x]!=head[y]){
                    if(depth[head[x]]<depth[head[y]]) swap(x,y);
                    ll cur=query(0,pos[head[x]],pos[x],0,n-1);
                 pali^=cur;
                    len+=abs(pos[head[x]]-pos[x])+1;
                    x=parent[head[x]];
                }
            if(depth[x]>depth[y]) swap(x,y);
             ll fial=query(0,pos[x],pos[y],0,n-1);
                len+=abs(pos[x]-pos[y])+1;
                pali^=fial;
                if(len&1){
                    ll cnt=0;
                    for(int i=25;i>=0;i--){
                        if((1ll<<i)&pali) cnt++;
                        if(cnt>1) {ans=false; break;}
                    }
                    aa.push_back(ans);
                } else {
                    for(ll i=0;i<26;i++){
                        if(pali&(1ll<<i)){
                            ans=false;
                            break;
                        }
                    }
                    aa.push_back(ans);
                }
            }
        }
        return aa;
    }
};