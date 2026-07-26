class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int pos1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int pos2 = nums[0] * nums[1] * nums[n - 1];
        return max(pos1, pos2);
    }
};

// TC : O(nlog n)
 