class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s, ans, temp, 0);
        return ans;
    }
    bool isPalindrome(string temp) {
        int i = 0;
        int j = temp.size() - 1;
        while (i < temp.size() && i <= j) {
            if (temp[i] != temp[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(string &s,vector<vector<string>> &ans,
               vector<string> &temp,
               int st) {
        if (st == s.size()) {
            ans.push_back(temp);
            return;
        }
        for (int end = st; end < s.size(); end++) {
            string slice = s.substr(st, end - st + 1);
            if (isPalindrome(slice)) {
                temp.push_back(slice);
                solve(s, ans, temp, end + 1);
                temp.pop_back();
            }
        }
    }
};