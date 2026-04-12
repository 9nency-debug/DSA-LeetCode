#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int memo[301][27][27];

    int dist(int a, int b) {
        if (a == -1) return 0; // Free finger can start anywhere
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }

    int solve(const string &word, int i, int f1, int f2) {
        if (i == static_cast<int>(word.size())) return 0;

        int &ans = memo[i][f1 + 1][f2 + 1];
        if (ans != -1) return ans;

        int curr = word[i] - 'A';

        // Option 1: Type current character with finger 1
        int useFinger1 = dist(f1, curr) + solve(word, i + 1, curr, f2);

        // Option 2: Type current character with finger 2
        int useFinger2 = dist(f2, curr) + solve(word, i + 1, f1, curr);

        return ans = min(useFinger1, useFinger2);
    }

    int minimumDistance(string word) {
        memset(memo, -1, sizeof(memo));
        return solve(word, 0, -1, -1);
    }
};
