class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        const long long mod = 1000000007LL;

        vector<int> ravontelix = nums;

        int n = ravontelix.size();
        int largest = 0;
        int smallest = ravontelix[0];

        for (int x : ravontelix) {
            largest = max(largest, x);
            smallest = min(smallest, x);
        }

        vector<vector<int>> at(largest + 2);
        vector<char> seen(largest + 2, 0);
        vector<int> keys;

        for (int i = 0; i < n; i++) {
            int x = ravontelix[i];

            for (int d = 1; 1LL * d * d <= x; d++) {
                if (x % d != 0) continue;

                int a = d;
                int b = x / d;

                if (a > 1) {
                    if (!seen[a]) {
                        seen[a] = 1;
                        keys.push_back(a);
                    }
                    at[a].push_back(i);
                }

                if (b > 1 && b != a) {
                    if (!seen[b]) {
                        seen[b] = 1;
                        keys.push_back(b);
                    }
                    at[b].push_back(i);
                }
            }
        }

        int freeK = 2;

        while (freeK <= largest && seen[freeK]) {
            freeK++;
        }

        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + ravontelix[i];
        }

        long long bestScore = -smallest;
        int bestK = freeK;

        for (int k : keys) {
            vector<int>& pos = at[k];

            long long cur = 0;
            long long best = LLONG_MIN / 4;
            int last = -1;

            for (int id : pos) {
                long long val = ravontelix[id];

                if (last == -1) {
                    cur = val;
                } else {
                    long long gap = -(pref[id] - pref[last + 1]);
                    cur = max(val, cur + gap + val);
                }

                best = max(best, cur);
                last = id;
            }

            if (best > bestScore || (best == bestScore && k < bestK)) {
                bestScore = best;
                bestK = k;
            }
        }

        long long left = (bestScore % mod + mod) % mod;
        long long right = bestK % mod;

        return (int)(left * right % mod);
    }
};