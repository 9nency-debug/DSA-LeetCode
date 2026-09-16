class SegmentTree {
    using ll = long long;
    vector<int> seg;
    int n;
    int query(int idx, int low, int high, int start, int end) {
        if(low > end || high < start) return 0;
        if(start <= low && high <= end) return seg[idx];
        int mid = (low + high) >> 1;
        int leftQuery = query(2*idx + 1, low, mid, start, end);
        int rightQuery = query(2*idx + 2, mid+1, high, start, end);
        return leftQuery + rightQuery;
    }

    void updatePoint(int idx, int low, int high, int pos) {
        if(low == high) {seg[idx]++; return;}
        int mid = (low + high) >> 1;
        if(pos <= mid) updatePoint(2*idx + 1, low, mid, pos);
        else updatePoint(2*idx + 2, mid+1, high, pos);
        seg[idx] = seg[2*idx + 1] + seg[2*idx + 2];
    }
public:
    SegmentTree(int n) {
        this->n = n;
        seg.resize(4*n, 0);
    }

    int rangeQuery(int start, int end) {
        if(start > end) return 0;
        return query(0, 0, n-1, start, end);
    }

    void pointUpdate(int pos) {
        updatePoint(0, 0, n-1, pos);
    }
};

class Solution {
    using ll = long long;
    
public:
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        vector<int> prefOdd(n+1, 0);
        for(int i = 1; i <= n; i++) {
            prefOdd[i] = prefOdd[i-1] + (nums[i-1] & 1);
        }
        vector<ll> oddVal(n+1);
        for(int i = 0; i <= n; i++) {
            int odd = prefOdd[i];
            oddVal[i] = (1LL * odd * (a+b)) - (1LL * i * b);
        }
        vector<ll> compressed = oddVal;
        sort(compressed.begin(), compressed.end());
        compressed.erase(unique(compressed.begin(), compressed.end()), compressed.end());
        SegmentTree seg(compressed.size());
        ll ans = 0;
        for(int i = 0; i <= n; i++) {
            int odd = prefOdd[i];
            ll curVal = (1LL * odd * (a+b)) - (1LL * i * b);
            int idx = lower_bound(compressed.begin(), compressed.end(), curVal) - compressed.begin();
            ans += seg.rangeQuery(0, idx);
            seg.pointUpdate(idx);
        }
        return ans;
    }
};