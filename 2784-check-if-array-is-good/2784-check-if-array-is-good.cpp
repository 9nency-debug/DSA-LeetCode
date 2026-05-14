// class Solution {
// public:
//     bool isGood(vector<int>& nums) {
        
//     }
// };

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        if(nums.size() != mx + 1) {
            return false;
        }

        vector<int> freq(mx + 1, 0);
        for(int num : nums) {
            if(num > mx || num < 1) {
                return false;
            }

            freq[num]++;
        }
        for(int i = 1; i < mx; i++) {
            if(freq[i] != 1) {
                return false;
            }
        }
        if(freq[mx] != 2) {
            return false;
        }

        return true;
    }
};