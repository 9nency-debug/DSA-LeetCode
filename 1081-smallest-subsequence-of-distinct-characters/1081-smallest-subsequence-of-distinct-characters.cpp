class Solution {
public:
    string smallestSubsequence(string s) {
        if (s.empty()) return "";
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;
        int pos = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] < s[pos])
                pos = i;
            freq[s[i] - 'a']--;
            if (freq[s[i] - 'a'] == 0)
                break;
        }
        char first = s[pos];
        string rem = "";
        for (int i = pos + 1; i < s.size(); i++) {
            if (s[i] != first)
                rem += s[i];
        }
        return first + smallestSubsequence(rem);
    }
};