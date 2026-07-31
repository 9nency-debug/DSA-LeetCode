class Solution {
long long nCr(int n, int r) {
    if (r > n - r) {
        r = n - r;
    }
    long long res = 1;
    for (int i = 0; i < r; ++i) {
        res = res * (n - i) / (i + 1);
    }
    return res;
}
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1);
        result[0] = result[rowIndex] = 1;
        for(int i = 1; i < rowIndex; i++){
             result[i] = (int)nCr(rowIndex, i);
           } 
       return result;
    }
};