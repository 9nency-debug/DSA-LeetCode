class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> PM(n), SM(n);
        PM[0] = nums[0];
        for(int i = 1; i < n; i++) {
            PM[i] = max(PM[i-1], nums[i]);
        }
        SM[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            SM[i] = min(SM[i+1], nums[i]);
        }
        for(int i = 0; i < n; i++) {
            if(PM[i] - SM[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};