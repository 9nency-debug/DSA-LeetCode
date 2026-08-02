class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
    int startColor = (start[0] + start[1]) % 2;
    int targetColor = (target[0] + target[1]) % 2;
    return startColor == targetColor;
    }
};

// may it can also work
// return (s[0] + s[1] + t[0] + t[1]) % 2 == 0;

