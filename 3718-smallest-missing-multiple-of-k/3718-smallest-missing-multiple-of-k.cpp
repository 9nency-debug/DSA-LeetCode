class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        // int max = *max_element(nums.begin(), nums.end());
        // for(int i = 1; i <= max + k; i++){
        //     int mul = i * k;
        //     if(find(nums.begin(), nums.end(), mul) != nums.end()){
        //         continue;
        //     } else {
        //         return mul;
        //     }
        // }
        // return k;

        // >>> Second Approach:
        unordered_map<int, bool> mp;
        for (auto it : nums) {
            if (it % k == 0) {
                mp[it / k] = true;
            }
        }
        int i = 1;
        while (true) {
            if (!mp[i]) {
                return i * k;
            }
            i++;
        }
    }
};