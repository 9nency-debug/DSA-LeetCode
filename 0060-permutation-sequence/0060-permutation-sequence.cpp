class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        vector<int> fact(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
            fact[i] = fact[i - 1] * i;
        }

        k--;

        string ans = "";

        for (int i = n; i >= 1; i--) {
            int blockSize = fact[i - 1];
            int idx = k / blockSize;

            ans += to_string(nums[idx]);
            nums.erase(nums.begin() + idx);

            k %= blockSize;
        }

        return ans;
    }
};