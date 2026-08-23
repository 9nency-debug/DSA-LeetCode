class Solution {
public:
    bool isPalindromic(string s) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int leftChar = s[i];
            int rightChar = s[n - 1 - i];
            for (int bit = 0; bit < 8; bit++) {
                int leftBit = (leftChar >> (7 - bit)) & 1;
                int rightBit = (rightChar >> bit) & 1;
                if (leftBit != rightBit)
                    return false;
            }
        }
        return true;
    }
};