class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n), suff(n);
        pref[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pref[i] = max(pref[i - 1], nums[i]);
        }
        suff[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = min(suff[i + 1], nums[i]);
        }
        vector<int> ans(n);
        int start = 0;
        int compMax = nums[0];
        for (int i = 0; i < n; i++) {
            compMax = max(compMax, nums[i]);
            bool split = (i == n - 1) || (pref[i] <= suff[i + 1]);
            if (split) {
                for (int j = start; j <= i; j++) {
                    ans[j] = compMax;
                }
                start = i + 1;
                if (start < n)
                    compMax = nums[start];
            }
        }
        return ans;
    }
};