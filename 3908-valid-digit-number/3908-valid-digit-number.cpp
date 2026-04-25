class Solution {
public:
    bool validDigit(int n, int x) {
        string s = to_string(n);
        
        if (s[0] - '0' == x) return false;
        
        for (char c : s) {
            if (c - '0' == x) return true;
        }
        
        return false;
    }
};