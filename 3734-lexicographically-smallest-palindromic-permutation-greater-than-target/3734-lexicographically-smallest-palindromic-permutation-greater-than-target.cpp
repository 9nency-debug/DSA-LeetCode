class Solution {
public:
    string ans = "";
    bool solve(string& half, vector<int>& hash, string& target, int i, bool greater, char& mid) {
        int n = target.size();
        int halfSize = n / 2;
        if(i == halfSize){
            string cur = half;
            if(n % 2)
                cur += mid;
            for(int j = half.size() - 1; j >= 0; j--)
                cur += half[j];
            if(cur > target){
                ans = cur;
                return true;
            }
            return false;
        }
        for(char c = 'a'; c <= 'z'; c++){
            if(hash[c - 'a'] == 0)
                continue;
            if(!greater && c < target[i])
                continue;
            half.push_back(c);
            hash[c - 'a']--;
            bool isGreater = greater || (c > target[i]);
            if(solve(half, hash, target, i + 1, isGreater, mid))
                return true;
            half.pop_back();
            hash[c - 'a']++;
        }
        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        ans = "";
        vector<int> hash(26, 0);
        for(char c : s)
            hash[c - 'a']++;
        char mid = '#';
        int odd = 0;
        for(int i = 0; i < 26; i++){
            if(hash[i] % 2){
                odd++;
                mid = char(i + 'a');
            }
            hash[i] /= 2;
        }
        if(odd > 1)
            return "";
        string half;
        solve(half, hash, target, 0, false, mid);
        return ans;
    }
};