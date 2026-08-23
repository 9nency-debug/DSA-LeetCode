class Solution {
public:
    bool solve(int s1, int s2, int q1, int q2) {
        if (s1 > s2 && q1 > q2) return true;
        if (s1 < s2 && q1 < q2) return true;
        if(q1==q2 && s1!=s2) return true;
        if (s1 == s2 && q1 == q2) return false;

        int sumDiff = abs(s1-s2);
        int qDiff = abs(q1-q2);
        int BobMoves = qDiff/2;
        if(qDiff%2==0 && sumDiff%9==0 && BobMoves ==sumDiff/9) return false;
        return true;
    }
    bool sumGame(string num) {
        int fq = 0, sq = 0, sum1 = 0, sum2 = 0;
        int n = num.size();
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') {
                fq++;
            } else {
                sum1 += num[i] - '0';
            }
        }
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') {
                sq++;
            } else {
                sum2 += num[i] - '0';
            }
        }
        return solve(sum1, sum2, fq, sq);       
    }
};