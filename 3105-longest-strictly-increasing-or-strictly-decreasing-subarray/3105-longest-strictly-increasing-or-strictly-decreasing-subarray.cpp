class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1, in = 1, dn = 1;
        for (int i = 1; i < nums.size(); i++) {
            if(nums[i - 1] < nums[i]) in++, dn = 1;
            else if(nums[i - 1] > nums[i]) dn++, in = 1;
            else dn = in = 1;
            ans = max({in, ans, dn});
        }
        return ans;
    }
};