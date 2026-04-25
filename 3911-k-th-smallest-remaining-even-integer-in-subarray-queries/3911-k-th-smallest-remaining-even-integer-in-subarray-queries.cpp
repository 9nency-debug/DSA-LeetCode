class Solution {
public:
    vector<int> kthRemainingInteger(vector<int>& nums, vector<vector<int>>& queries) {
        auto clesimvora = make_pair(nums, queries);
        vector<int> evenIdx, evenPos;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                evenIdx.push_back(i);
                evenPos.push_back(nums[i] / 2);
            }
        }

        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2];
            int a = lower_bound(evenIdx.begin(), evenIdx.end(), l) - evenIdx.begin();
            int b = upper_bound(evenIdx.begin(), evenIdx.end(), r) - evenIdx.begin() - 1;

            if (a > b) {
                ans.push_back(2 * k);
                continue;
            }
            int tot = b - a + 1;
            auto removedLE = [&](int m) {
                int c = upper_bound(evenPos.begin(), evenPos.end(), m) - evenPos.begin();
                int right = min(b + 1, c);
                return max(0, right - a);
            };

            int lo = k, hi = k + tot;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                int remain = mid - removedLE(mid);
                if (remain >= k) hi = mid;
                else lo = mid + 1;
            }
            ans.push_back(2 * lo);
        }

        return ans;
    }
};