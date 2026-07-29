class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxEnding = nums[0];
        int minEnding = nums[0];
        int maxSum = nums[0];
        int minSum = nums[0];
        int sum = nums[0];
        for(int i=1;i<n;i++){
            sum += nums[i];
            maxEnding = max(maxEnding + nums[i], nums[i]);
            maxSum = max(maxSum, maxEnding);
            minEnding = min(minEnding + nums[i], nums[i]);
            minSum = min(minSum, minEnding);
        }
        if(maxSum < 0) return maxSum;
        return max(maxSum, sum - minSum);
    }
};