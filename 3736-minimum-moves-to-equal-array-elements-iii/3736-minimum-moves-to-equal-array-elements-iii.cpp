class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max = nums[0];
        for(int value : nums) {
            if(value > max) {
                max = value;
            }
        }
        int total_Moves = 0;
        for(int value : nums) {
            total_Moves += (max - value);
        }
        return total_Moves;
    }
};