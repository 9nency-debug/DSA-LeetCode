class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++) {
            int diff = nums[i+1] - nums[i];
            if(diff > 1) {
                int missingCount = diff - 1;
                for(int j = 1; j <= missingCount; j++) {
                    ans.push_back(nums[i] + j);
                }
            }
        }
        return ans;
    }
};