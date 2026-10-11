class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int square = 1;
        for(int i = 0 ; i < n; i++) {
            // if(i == 0) continue;
            if(n % (i + 1) == 0) {
                square = (nums[i] * nums[i]);
                sum += square;
            }
        }
            return sum;
    }
};