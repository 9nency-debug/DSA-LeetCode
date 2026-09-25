class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reach = 0;
        for (int i = 0; i < n; i++) {
            if(i > reach || reach >= n-1) break;
            reach = max(reach, i + nums[i]);
        }
        if (reach >= n-1) return true;
        return false;
    }
};