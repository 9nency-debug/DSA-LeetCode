class Solution {
public:
    int minimumPushes(string word) {
        int count = 0;
        unordered_map<int, int>mp;
        int st = 2;
        for(char &ch : word) {
            if(st > 9) {
                st = 2;
            }
            mp[st]++;
            count += mp[st];
            st++;
        }
        return count;
    }
};