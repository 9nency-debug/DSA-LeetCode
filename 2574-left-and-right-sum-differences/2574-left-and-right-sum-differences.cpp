class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int leftSum = 0;
        int rightSum = 0;
        for(int num: nums) {
            rightSum += num;
        }
        vector<int> answer(n);
        for(int i = 0; i<n;i++) {
            rightSum-=nums[i];
            answer[i] = abs(leftSum - rightSum);
            leftSum += nums[i];
        }
        return answer;
    }
};