// class SegTree {
// public:
//     int n;
//     vector<int> tree;
//     SegTree(int n) : n(n) {
//         tree.resize(4 * n);
//     }

//     int gcd(int a, int b) {
//         return b == 0 ? a : gcd(b, a % b);
//     }

//     void build(vector<int>& arr, int node, int l, int r) {
//         if (l == r) {
//             tree[node] = arr[l];
//             return;
//         }
//         int mid = (l + r) / 2;
//         build(arr, 2*node, l, mid);
//         build(arr, 2*node+1, mid+1, r);
//         tree[node] = gcd(tree[2*node], tree[2*node+1]);
//     }

//     void update(int node, int l, int r, int idx, int val) {
//         if (l == r) {
//             tree[node] = val;
//             return;
//         }
//         int mid = (l + r) / 2;
//         if (idx <= mid)
//             update(2*node, l, mid, idx, val);
//         else
//             update(2*node+1, mid+1, r, idx, val);

//         tree[node] = gcd(tree[2*node], tree[2*node+1]);
//     }

//     int query() {
//         return tree[1];
//     }
// };

// class Solution {
// public:
//     int gcd(int a, int b) {
//         return b == 0 ? a : gcd(b, a % b);
//         }

// int countGoodSubseq(vector<int>& nums, int p, vector<vector<int>>& queries) {
//         int n = nums.size();
//         vector<int> b(n);
//         int cnt = 0;
//         for (int i = 0; i < n; i++) {
//             if (nums[i] % p == 0) {
//                 b[i] = nums[i] / p;
//                 cnt++;
//             } else {
//                 b[i] = 0;
//             }
//         }

//         SegTree st(n);
//         st.build(b, 1, 0, n - 1);
//         int ans = 0;
//         for (auto &q : queries) {
//             int idx = q[0], val = q[1];
//             if (nums[idx] % p == 0) cnt--;
//             nums[idx] = val;
//             if (nums[idx] % p == 0) {
//                 b[idx] = nums[idx] / p;
//                 cnt++;
//             } else {
//                 b[idx] = 0;
//             }

//             st.update(1, 0, n - 1, idx, b[idx]);

//             if (cnt >= 2 && st.query() == 1) {
//                 ans++;
//             }
//         }

//         return ans;
//     }
// };

// class SegTree {
// public:
//     int n;
//     vector<int> tree;

//     SegTree(int n) : n(n) {
//         tree.resize(4 * n);
//     }

//     int gcd(int a, int b) {
//         return b == 0 ? a : gcd(b, a % b);
//     }

//     void build(vector<int>& arr, int node, int l, int r) {
//         if (l == r) {
//             tree[node] = arr[l];
//             return;
//         }
//         int mid = (l + r) / 2;
//         build(arr, 2*node, l, mid);
//         build(arr, 2*node+1, mid+1, r);
//         tree[node] = gcd(tree[2*node], tree[2*node+1]);
//     }

//     void update(int node, int l, int r, int idx, int val) {
//         if (l == r) {
//             tree[node] = val;
//             return;
//         }
//         int mid = (l + r) / 2;
//         if (idx <= mid)
//             update(2*node, l, mid, idx, val);
//         else
//             update(2*node+1, mid+1, r, idx, val);

//         tree[node] = gcd(tree[2*node], tree[2*node+1]);
//     }

//     int query() {
//         return tree[1];
//     }
// };

// class Solution {
// public:
//     int countGoodSubseq(vector<int>& nums, int p, vector<vector<int>>& queries) {
//         int n = nums.size();

//         vector<int> b(n);
//         int cnt = 0;
//         for (int i = 0; i < n; i++) {
//             if (nums[i] % p == 0) {
//                 b[i] = nums[i] / p;
//                 cnt++;
//             } else {
//                 b[i] = 0;
//             }
//         }

//         SegTree st(n);
//         st.build(b, 1, 0, n - 1);
//         int ans = 0;
//         for (auto &q : queries) {
//             int idx = q[0], val = q[1];
//             if (nums[idx] % p == 0) cnt--;
//             nums[idx] = val;
//             if (nums[idx] % p == 0) {
//                 b[idx] = nums[idx] / p;
//                 cnt++;
//             } else {
//                 b[idx] = 0;
//             }

//             st.update(1, 0, n - 1, idx, b[idx]);

//             if (cnt >= 2 && st.query() == 1) {
//                 ans++;
//             }
//         }

//         return ans;
//     }
// };

// class SegTree {
// public:
//     int n;
//     vector<int> tree;
//     SegTree(int n) : n(n) {
//         tree.resize(4 * n);
//     }

//     int gcd(int a, int b) {
//         return b == 0 ? a : gcd(b, a % b);
//     }

//     void build(vector<int>& arr, int node, int l, int r) {
//         if (l == r) {
//             tree[node] = arr[l];
//             return;
//         }
//         int mid = (l + r) / 2;
//         build(arr, 2*node, l, mid);
//         build(arr, 2*node+1, mid+1, r);
//         tree[node] = gcd(tree[2*node], tree[2*node+1]);
//     }

//     void update(int node, int l, int r, int idx, int val) {
//         if (l == r) {
//             tree[node] = val;
//             return;
//         }
//         int mid = (l + r) / 2;
//         if (idx <= mid)
//             update(2*node, l, mid, idx, val);
//         else
//             update(2*node+1, mid+1, r, idx, val);

//         tree[node] = gcd(tree[2*node], tree[2*node+1]);
//     }

//     int query() {
//         return tree[1];
//     }
// };

// class Solution {
// public:
//     int countGoodSubseq(vector<int>& nums, int p, vector<vector<int>>& queries) {

//         int n = nums.size();
//         vector<int> b(n, 0);

//         int cnt = 0;
//         int freq1 = 0;
//         for (int i = 0; i < n; i++) {
//             if (nums[i] % p == 0) {
//                 b[i] = nums[i] / p;
//                 cnt++;
//                 if (b[i] == 1) freq1++;
//             }
//         }

//         SegTree st(n);
//         st.build(b, 1, 0, n - 1);
//         int ans = 0;

//         for (auto &q : queries) {
//             int idx = q[0], val = q[1];
//             if (nums[idx] % p == 0) {
//                 cnt--;
//                 if (b[idx] == 1) freq1--;
//             }
//             nums[idx] = val;
//             if (nums[idx] % p == 0) {
//                 b[idx] = nums[idx] / p;
//                 cnt++;
//                 if (b[idx] == 1) freq1++;
//             } else {
//                 b[idx] = 0;
//             }

//             st.update(1, 0, n - 1, idx, b[idx]);
//             bool ok = false;
//             if (freq1 > 0) {
//                 ok = true;
//             }
//             // else if (cnt >= 2) {
//             //     if (st.query() == 1) {
//             //         ok = true;
//             //     }
//             // }
//             // else if (cnt >= 2) {
//             //     if (st.query() == 1) {
//             //         if (cnt >= 3)
//             //         ok = true;
//             //     }
//             // }

// else if (cnt >= 2) {
//     if (st.query() == 1) {
//         for (int i = 0; i < n; i++) {
//             if (b[i] == 0) continue;
//             int old = b[i];
//             st.update(1, 0, n - 1, i, 0);
//             if (st.query() == 1) {
//                 ok = true;
//                 st.update(1, 0, n - 1, i, old);
//                 break;
//             }

//             st.update(1, 0, n - 1, i, old);
//         }
//     }
// }

//             if (ok) 
//             ans++;
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     struct Node {
//         int g;
//         vector<int> pre, suf;
//     };

//     int gcd(int a, int b) {
//         return b == 0 ? a : gcd(b, a % b);
//     }

//     Node merge(Node &L, Node &R) {
//         if (L.pre.empty()) return R;
//         if (R.pre.empty()) return L;

//         Node res;
//         res.g = gcd(L.g, R.g);
//         res.pre = L.pre;
//         for (int x : R.pre) {
//             int val = gcd(L.g, x);
//             if (res.pre.empty() || res.pre.back() != val)
//                 res.pre.push_back(val);
//         }
//         res.suf = R.suf;
//         for (int x : L.suf) {
//             int val = gcd(R.g, x);
//             if (res.suf.empty() || res.suf.back() != val)
//                 res.suf.push_back(val);
//         }

//         return res;
//     }

//     struct SegTree {
//         struct Node {
//             int g;
//             vector<int> pre, suf;
//         };

//         int n;
//         vector<Node> tree;
//         SegTree(int n) : n(n), tree(4*n) {}
//         int gcd(int a, int b) {
//             return b == 0 ? a : gcd(b, a % b);
//         }

//         Node make_node(int val) {
//             Node node;
//             node.g = val;
//             if (val > 0) {
//                 node.pre = {val};
//                 node.suf = {val};
//             }
//             return node;
//         }

//     Node merge(Node &L, Node &R) {
//         if (L.pre.empty()) 
//             return R;
//         if (R.pre.empty()) 
//             return L;

//         Node res;
//         res.g = gcd(L.g, R.g);
//         for (int x : R.pre) {
//             int val = gcd(L.g, x);
//             if (res.pre.empty() || res.pre.back() != val)
//                 res.pre.push_back(val);
//         }
//         res.suf = R.suf;
//         for (int x : L.suf) {
//             int val = gcd(R.g, x);
//             if (res.suf.empty() || res.suf.back() != val)
//                 res.suf.push_back(val);
//         }

//         return res;
//     }

//     void build(vector<int>& a, int p, int l, int r) {
//         if (l == r) {
//             tree[p] = make_node(a[l]);
//             return;
//         }
//         int m = (l + r) / 2;
//         build(a, 2*p, l, m);
//         build(a, 2*p+1, m+1, r);
//         tree[p] = merge(tree[2*p], tree[2*p+1]);
//     }

//     void update(int p, int l, int r, int i, int val) {
//         if (l == r) {
//             tree[p] = make_node(val);
//             return;
//         }
//         int m = (l + r) / 2;
//         if (i <= m) update(2*p, l, m, i, val);
//         else update(2*p+1, m+1, r, i, val);

//         tree[p] = merge(tree[2*p], tree[2*p+1]);
//     }
// };

//     int countGoodSubseq(vector<int>& nums, int p, vector<vector<int>>& queries) {
//         int n = nums.size();
//         vector<int> b(n, 0);
//         int freq1 = 0;

//         for (int i = 0; i < n; i++) {
//             if (nums[i] % p == 0) {
//                 b[i] = nums[i] / p;
//                 if (b[i] == 1) freq1++;
//             }
//         }

//         SegTree st(n);
//         st.build(b, 1, 0, n-1);
//         int ans = 0;
//         for (auto &q : queries) {
//             int i = q[0], val = q[1];
//             if (nums[i] % p == 0 && b[i] == 1) freq1--;
//             nums[i] = val;

//             if (nums[i] % p == 0) {
//                 b[i] = nums[i] / p;
//                 if (b[i] == 1) freq1++;
//             } else {
//                 b[i] = 0;
//             }

//             st.update(1, 0, n-1, i, b[i]);
//             bool ok = false;
//             if (freq1 > 0) ok = true;
//             else {
//                 auto &root = st.tree[1];
//                 for (int x : root.pre) 
//                     if (x == 1) 
//                     ok = true;
//                 for (int x : root.suf) 
//                     if (x == 1) 
//                     ok = true;
//             }

//             if (ok) 
//             ans++;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int n, P;
    vector<int> seg, arr;
    int gcdv(int a,int b){
        if(!a) return b;
        if(!b) return a;
        return gcd(a,b);
    }

    void build(int i,int l,int r){
        if(l==r){
            seg[i] = (arr[l]%P==0 ? arr[l]/P : 0);
            return;
        }

        int m=(l+r)/2;
        build(i*2,l,m);
        build(i*2+1,m+1,r);
        seg[i]=gcdv(seg[i*2],seg[i*2+1]);
    }

    void update(int i,int l,int r,int idx,int val){
        if(l==r){
            seg[i]=(val%P==0 ? val/P : 0);
            return;
        }

        int m=(l+r)/2;
        if(idx<=m) update(i*2,l,m,idx,val);
        else update(i*2+1,m+1,r,idx,val);
        seg[i]=gcdv(seg[i*2],seg[i*2+1]);
    }

    bool canExcludeOne(int i,int l,int r,int ext){
        if(l==r) return ext==1;
        int m=(l+r)/2;

        int left  = gcdv(ext, seg[i*2+1]);
        int right = gcdv(ext, seg[i*2]);
        if(left==1 || right==1) 
            return true;

        return canExcludeOne(i*2,l,m,left) ||
               canExcludeOne(i*2+1,m+1,r,right);
    }

    int countGoodSubseq(vector<int>& nums, int p, vector<vector<int>>& queries) {

        arr = nums;
        P = p;
        n = arr.size();
        seg.assign(4*n,0);
        int cnt = 0;
        for(int x:arr) if(x%P==0) cnt++;
        build(1,0,n-1);
        int ans=0;

        for(auto &q:queries){
            int idx=q[0], val=q[1];

            if(arr[idx]%P==0) cnt--;
            if(val%P==0) cnt++;
            arr[idx]=val;
            update(1,0,n-1,idx,val);

            if(seg[1]==1){
                if(cnt<n) ans++;
                else if(canExcludeOne(1,0,n-1,0)) ans++;
            }
        }

        return ans;
    }
};