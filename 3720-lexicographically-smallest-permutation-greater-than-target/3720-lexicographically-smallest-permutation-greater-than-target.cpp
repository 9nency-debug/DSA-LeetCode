class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }
        for (int pos = n - 1; pos >= 0; pos--) {
            vector<int> temp = freq;
            bool possible = true;
            for (int i = 0; i < pos; i++) {
                int ch = target[i] - 'a';
                if (temp[ch] == 0) {
                    possible = false;
                    break;
                }
                temp[ch]--;
            }
            if (possible == false) {
                continue;
            }
            int ch = target[pos] - 'a';
            int bigger = -1;
            for (int j = ch + 1; j < 26; j++) {
                if (temp[j] > 0) {
                    bigger = j;
                    break;
                }
            }
            if (bigger == -1) {
                continue;
            }
            string ans = "";
            for (int i = 0; i < pos; i++) {
                ans += target[i];
            }
            ans += char('a' + bigger);
            temp[bigger]--;
            for (int j = 0; j < 26; j++) {
                while (temp[j] > 0) {
                    ans += char('a' + j);
                    temp[j]--;
                }
            }
            return ans;
        }
        return "";
    }
};