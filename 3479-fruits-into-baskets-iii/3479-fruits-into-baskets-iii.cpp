class SegmentTree {
    int N;
    vector<int> tree;
public:
    SegmentTree(const vector<int>& baskets) {
        int n = baskets.size();
        N = 1;
        while (N < n) N <<= 1;
        tree.resize(N << 1, -1);
        for (int i = 0; i < n; ++i)
            tree[N + i] = baskets[i];
        for (int i = N - 1; i >= 1; --i)
            tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }
    bool placeFruit(int val) {
        int idx = 1;
        if (tree[idx] < val) return false;
        while (idx < N) {
            if (tree[2 * idx] >= val)
                idx = 2 * idx;
            else
                idx = 2 * idx + 1;
        }
        tree[idx] = -1;
        while (idx > 1) {
            idx >>= 1;
            tree[idx] = max(tree[2 * idx], tree[2 * idx + 1]);
        }
        return true;
    }
};
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        SegmentTree seg(baskets);
        int unplaced = 0;
        for (int fruit : fruits) {
            if (!seg.placeFruit(fruit))
                ++unplaced;
        }
        return unplaced;
    }
};