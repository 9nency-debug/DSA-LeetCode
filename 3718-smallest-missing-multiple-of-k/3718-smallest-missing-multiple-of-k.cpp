class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int max = *max_element(nums.begin(), nums.end());
        for(int i = 1; i <= max + k; i++){
            int mul = i * k;
            if(find(nums.begin(), nums.end(), mul) != nums.end()){
                continue;
            } else {
                return mul;
            }
        }
        return k;
    }
};