class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int left = 0, right = 0;
        int longest = 0;
        while(right < n)
        {
            mp[nums[right]]++;
            while(left < right && mp[nums[right]] > k)
            {
                mp[nums[left]]--;
                left++;
            }
            longest = max(longest, right - left + 1);
            right++;
        }
        return longest;
    }
};