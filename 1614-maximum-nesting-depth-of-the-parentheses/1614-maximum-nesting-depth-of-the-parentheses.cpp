class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = 0;
        int count = 0;
        for (char ch : s) {
            if (ch == '(') {
                count++;
                if (count > maxDepth) {
                    maxDepth = count;
                }
            } else if (ch == ')') {
                count--;
            }
        }
        return maxDepth;
    }
};