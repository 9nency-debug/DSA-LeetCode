class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int, vector<int>> mp;
        for(int i =0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        int ans = 0;
        for(auto it : mp){
            vector<int> pos = it.second;
            if(pos.size() == 3) {
                if(pos[1] - pos[0] == pos[2] - pos[1]) {
                    ans++;
                }
            }
        }
        return ans;
    }
};