class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        int minEven = INT_MAX;
        int odd = 0, even = 0;
        for(int x : nums1) {
            if(x % 2) {
                odd++;
                minOdd = min(minOdd, x);
            } else {
                even++;
                minEven = min(minEven, x);
            }
        }
        if(odd == 0 || even == 0) return true;
        return minOdd < minEven;
    }
};

