class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for(int i = 0 ; i < nums.size(); i++){
            mp[nums[i]].push_back(i);
        }
        int ans = 0;
        for(auto it : mp) {
        vector<int>& pos = it.second;
        if(pos.size() < 3) continue;
        int diff = pos[1] - pos[0];
        bool special = true;
        for(int i = 2; i < pos.size(); i++) {
            if(pos[i] - pos[i - 1] != diff) {
                special = false;
                break;
            }
        }
        if(special) ans++;
    }
    return ans;
    }
};