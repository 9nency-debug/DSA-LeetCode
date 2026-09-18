class Solution {
public:
    int residuePrefixes(string s) {
        // vector<int> v; -> use unordered_set of char }-as-> unordered_set<char> str;
        // int str = s.size(); |->  .length()
        // for(ch : v[i]) 
        //     if(str == str[i-1] % 3) {
        //     return;
        //     }
        unordered_set<char> str;
        int result = 0;
        for(int i = 0; i < s.length(); ++i) {
            str.insert(s[i]);
            if(str.size() == (i + 1) % 3) result++;
            if(str.size() > 2) break;
        }
        return result;
    }
};
