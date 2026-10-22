class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (is_sorted(nums.begin(), nums.end())) return 0;
        bool ascending = true;
        bool descending = true;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != (nums[0] + i) % n)
                ascending = false;
            if (nums[i] != (nums[0] - i + n) % n)
                descending = false;
        }
        if (ascending) {
            int k = nums[0];
            return min(n - k, k + 2);
        }
        if (descending) {
            int k = (nums[0] + 1) % n;
            return 1 + min(k, n - k);
        }
        return -1;
    }
};
