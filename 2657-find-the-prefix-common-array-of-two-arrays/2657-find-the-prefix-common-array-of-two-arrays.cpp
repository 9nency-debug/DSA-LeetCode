class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> C(n);
        vector<int> freqArr(n+1, 0);
        int twoCount = 0;

        for (int i = 0; i < n; i++) {
            freqArr[A[i]]++;
            if (freqArr[A[i]] == 2) {
                twoCount++;
            }

            freqArr[B[i]]++;
            if (freqArr[B[i]] == 2) {
                twoCount++;
            }

            C[i] = twoCount;
        }
        return C;
    }
};