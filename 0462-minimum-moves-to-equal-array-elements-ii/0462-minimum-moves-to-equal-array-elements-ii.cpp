class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        sort(nums.begin(), nums.end());
        int mid = nums[n / 2];
        int res = 0;
        for (int i : nums) res += abs(i - mid);
        return res;
    }
};