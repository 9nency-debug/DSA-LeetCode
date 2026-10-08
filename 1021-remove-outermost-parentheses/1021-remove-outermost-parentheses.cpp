class Solution {
public:
    string removeOuterParentheses(string s) {
        int start = 0, opens = 0, closes = 0;
        string answer;
        for (int end = 0; end < (int)s.size(); ++end) {
            if (s[end] == '(') ++opens;
            else ++closes;
            if (opens == closes) {
                answer += s.substr(start + 1, end - start - 1);
                start = end + 1;
            }
        }
        return answer;
    }
};