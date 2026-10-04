class Solution {
public:
    bool checkValidString(string s) {
        int left = 0;
        int h = 0;
        for( auto& c : s) {
             left += ((c == '(') << 1) - 1;
             h += ((c != ')') << 1) - 1;
             if(h<0) return 0;
             left = max(left, 0);
        }
        return left == 0;
    }
};