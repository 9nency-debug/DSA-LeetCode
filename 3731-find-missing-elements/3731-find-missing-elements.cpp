class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++) {
            int next = nums[i] + 1;
            while(next < nums[i + 1]) {
                ans.push_back(next);
                next++;
            }
        }
        return ans;
    }
};