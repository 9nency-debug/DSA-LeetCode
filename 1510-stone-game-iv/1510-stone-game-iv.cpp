class Solution {
public:
    unordered_map<int, bool> memo;
    bool solve(int n) {
        if (n == 0) return false;
        if (memo.find(n) != memo.end())
            return memo[n];
        for (int i = 1; i * i <= n; i++) {
            int square = i * i;
            if (solve(n - square) == false) {
                return memo[n] = true;
            }
        }
        return memo[n] = false;
    }
    bool winnerSquareGame(int n) {
        return solve(n);
    }
};