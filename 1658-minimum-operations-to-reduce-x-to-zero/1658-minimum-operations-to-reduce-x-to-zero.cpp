class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int minOperation = INT_MAX;
        int size = nums.size();
        int curSum = 0;
        int left = -1;
        int right = size;
        while(left < size - 1 && curSum < x) {
            curSum += nums[++left];
        }
        if(curSum == x) {
            minOperation = min(minOperation, left + 1);
        }
        while(left >= 0) {
            curSum -= nums[left--];
            while(right > left + 1 && curSum < x) {
                curSum += nums[--right];
            }
            if(curSum == x) {
                minOperation = min(minOperation, (left + 1) + (size - right));
            }
        }
        return minOperation == INT_MAX ? -1 : minOperation;
    }
};