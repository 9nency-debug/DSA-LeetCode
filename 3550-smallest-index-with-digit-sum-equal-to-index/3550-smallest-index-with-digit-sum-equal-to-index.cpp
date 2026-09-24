class Solution {
private:
    int sum(int num) {
        int s = 0;
        while(num > 0) {
            s += num % 10;
            num/=10;
        }
        return s;
    }
public:
    int smallestIndex(vector<int>& nums) {
        for(int i = 0 ; i < nums.size() ; i++) {
            if(i == sum(nums[i])) {
                return i;
            }
        }
        return -1;
    }
};