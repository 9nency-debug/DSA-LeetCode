class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        for (char ch : t) {
            need[ch]++;
        }

        int left = 0;
        int count = t.size();
        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {
            char ch = s[right];
            if (need[ch] > 0) {
                count--;
            }
            need[ch]--;
            while (count == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                need[s[left]]++;;;;;;;;;;;;;
                if (need[s[left]] > 0) {
                    count++;
                }
                left++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};