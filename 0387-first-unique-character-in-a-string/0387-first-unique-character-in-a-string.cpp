/*class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        for(char c : s) map[c]++;
        for(int i = 0; i < s.length(); i++) {
            if(map[s[i]] == 1) {
                return 1;
            }
        } 
        return -1;
    }
};
*/
class Solution {
public:
    int firstUniqChar(string s) {
        int frequency[26] = {0};
        for (char c : s) {
            frequency[c - 'a']++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (frequency[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};
