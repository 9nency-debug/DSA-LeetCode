class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        const long long INF = LLONG_MAX / 4;
        long long first = INF;
        long long second = INF;
        long long third = 0;
        for (int i = 1; i <= n; ++i) {
            long long temp = min(first + 9, min(second + 4, third + 1));
            temp += costs[i - 1];
            first = second;
            second = third;
            third = temp;
        }
        return static_cast<int>(third);
    }
};