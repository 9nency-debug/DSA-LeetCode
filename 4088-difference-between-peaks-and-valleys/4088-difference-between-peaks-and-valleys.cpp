class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int n = nums.size();
        int peak_sum = 0, valley_sum = 0;
        for(int i = 1; i < n - 1; i++) {
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
                peak_sum += nums[i];
            } else if(nums[i] < nums[i-1] && nums[i] < nums[i+1]) {
                valley_sum += nums[i];
            }
        }
            return (peak_sum - valley_sum);
    }
};