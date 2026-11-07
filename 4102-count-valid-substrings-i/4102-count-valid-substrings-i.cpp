class Solution {
public:
    long long countValidSubstrings(string s) {
        int n= s.size();
        int left = 0;
        long long ans =0;
        for(int right = 0; right < n; right++) {
            while(right - left + 1 >= 3 && s.substr(right - 2, 3) == "abc") {
                left++;
            }
            ans+= (right - left + 1);
        }
        return ans;
    }

};