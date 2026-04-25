class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
        int peak = 0;
        
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[peak]) peak = i;
        }
        
        long long asc = 0, desc = 0;
        for (int i = 0; i <= peak; i++) 
            asc += nums[i];
        for (int i = peak; i < n; i++) 
            desc += nums[i];
        
        if (asc > desc) 
            return 0;
        if (desc > asc) 
            return 1;
        return -1;
    }
};