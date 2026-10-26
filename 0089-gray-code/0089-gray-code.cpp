class Solution {
public:
    vector<int> grayCode(int n) {
        int size = 1 << n;
        vector<int> grayCode(size);
        for (int i = 0; i < size; ++i)
            grayCode[i] = i ^ (i >> 1);
        return grayCode;
    }
};