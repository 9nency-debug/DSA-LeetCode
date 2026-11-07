class Solution {
public:
    bool repeatedStringMatch(string a, string b, int x, int y) {
        long long p = a.size();
        long long q = b.size();
        long long totalLength = p * x;
        long long targetLength = q * y;
        if(targetLength > totalLength) {
            return false;
        }
        long long limit = p + q -gcd(p, q);
        long long k = min(targetLength, limit);
        for(int start = 0; start < p; start++) {
            if(start+targetLength >totalLength) {
                continue;
            }
            bool match = true;
            for(int j = 0; j < k; j++) {
                if(a[(start + j) % p] != b[j % q]) {
                    match = false;
                    break;
                }
            }
            if(match) {
                return true;
            }
        }
        return false;
    }
};