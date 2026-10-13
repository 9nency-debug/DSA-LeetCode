class Solution {
public:
    long long solve(vector<long long>& arr, int index) {
        if (index == arr.size()) {
            return 0;
        }
        if (index % 2 == 0) {
            return arr[index] + solve(arr, index + 1);
        }
        return -arr[index] + solve(arr, index + 1);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> squares;
        for (int x : nums) {
            squares.push_back(1LL * x * x);
        }
        sort(squares.begin(), squares.end());
        vector<long long> arr(n);
        int left = 0;
        int right = n - 1;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                arr[i] = squares[right--];
            } else {
                arr[i] = squares[left++];
            }
        }
        return solve(arr, 0);
    }
};