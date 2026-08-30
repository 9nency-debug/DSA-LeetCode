class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxIdx = 0, minIdx = 0;
        int n = nums.size();
        if (n == 1) return 1;
        for (int i = 0; i < n; i++) {
            if(nums[i] > nums[maxIdx]) maxIdx = i;
            if(nums[i] < nums[minIdx]) minIdx = i;
        }
        if (minIdx > maxIdx) swap(minIdx, maxIdx);
        return min((n - maxIdx) + min(minIdx + 1, maxIdx - minIdx),(minIdx + 1) + min(n - maxIdx, maxIdx - minIdx));
    }
};