#include<iostream>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = -1;   // prefix sum 0 at index -1

        int sum = 0;
        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                sum -= 1;
            else
                sum += 1;

            if (mp.find(sum) != mp.end()) {
                maxLen = max(maxLen, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }
        return maxLen;
    }
};
