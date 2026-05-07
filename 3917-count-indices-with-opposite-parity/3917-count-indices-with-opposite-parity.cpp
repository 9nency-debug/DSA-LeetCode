class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 0);

        int evenCount = 0, oddCount = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] % 2 == 0) {
                answer[i] = oddCount;
                evenCount++;
            } else {
                answer[i] = evenCount;
                oddCount++;
            }
        }

        return answer;
    }
};