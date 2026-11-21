class Solution {
public:
    vector<vector<int>> tree;
    vector<int> ans;
    int helper(int node,string& s,unordered_map<int,int>& m){
        if(m.count(s[node])){
            auto temp = m[s[node]];
            ans[node] = 1;
            m[s[node]] = node;
            for(auto& ele : tree[node]){
                ans[node]+=helper(ele,s,m);
            }
            ans[temp]+=ans[node];
            m[s[node]] = temp;
            return 0;
        }else{
            m[s[node]] = node;
            int size = 1;
            for(auto& ele : tree[node]){
                size+=helper(ele,s,m);
            }
            m.erase(s[node]);
            return ans[node] += size;
        }
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        tree.resize(n);
        for(int i = 1;i<n;i++){
            tree[parent[i]].push_back(i);
        }
        ans.assign(n,0);
        unordered_map<int,int> m;
        helper(0,s,m);
        return ans;      
    }
};