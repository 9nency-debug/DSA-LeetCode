class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.size();
        int lastA = -1;
        int lastAB = -1;
        int left = 0;
        long long ans = 0;
        for (int i = 0; i< n; i++) {
            if(s[i] == 'a') {
                // if(lastA == -1) {
                    lastA = i;
                } else if(s[i]=='b') {
                    if(lastA!=-1){
                        // if(abStart = -1)
                        //     abStart = lastA;
                        // else
                        //     abStart = min(abStart, lastA);
                        lastAB = max(lastAB, lastA);
                    }
                } else {
                if(lastAB != -1) {
                    // if(lastAB != -1) {
                        // if(badStart == -1)
                        // badStart = abStart;
                        // else 
                        // badStart = min(badStart, abStart);
                        left = max(left, lastAB + 1);
                    }
                }
                ans += (i - left + 1);
                // if(badStart == -1) {
                //     ans += (i + 1);
                // } else {
                //     ans += (i - badStart);
                // }
            }
            return ans;
        
    }
};