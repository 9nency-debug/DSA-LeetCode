class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > num * 9) {
            return "";
        }
        int k = sum / 9;
        int r = sum % 9;
        string ans(k, '9');
        if (r > 0) {
            ans += char('0' + r);
        }
        ans += string(num - ans.size(), '0');
        return ans;
    }
};