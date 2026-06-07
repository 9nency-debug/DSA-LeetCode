class Solution {
public:
    struct State {
        long long val;
        int cnt;
    };

    bool better(State a, State b) {
        if (a.val != b.val) return a.val > b.val;
        return a.cnt < b.cnt; // important: fewer subarrays on tie
    }

    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n = nums.size();

        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        auto solve = [&](long long penalty) {
            vector<State> dp(n + 1, {0, 0});
            deque<int> dq;

            auto candVal = [&](int idx) {
                return dp[idx].val - pref[idx];
            };

            auto betterIndex = [&](int a, int b) {
                long long va = candVal(a);
                long long vb = candVal(b);

                if (va != vb) return va > vb;
                return dp[a].cnt < dp[b].cnt;
            };

            for (int i = 1; i <= n; i++) {
                int add = i - l;

                if (add >= 0) {
                    while (!dq.empty() && betterIndex(add, dq.back())) {
                        dq.pop_back();
                    }
                    dq.push_back(add);
                }

                while (!dq.empty() && dq.front() < i - r) {
                    dq.pop_front();
                }

                State best = dp[i - 1];

                if (!dq.empty()) {
                    int start = dq.front();

                    State take;
                    take.val = pref[i] + dp[start].val - pref[start] - penalty;
                    take.cnt = dp[start].cnt + 1;

                    if (better(take, best)) {
                        best = take;
                    }
                }

                dp[i] = best;
            }

            return dp[n];
        };

        // Best single valid subarray, needed because we must choose at least one.
        long long bestOne = LLONG_MIN / 4;
        deque<int> dq;

        for (int i = 1; i <= n; i++) {
            int add = i - l;

            if (add >= 0) {
                while (!dq.empty() && pref[dq.back()] >= pref[add]) {
                    dq.pop_back();
                }
                dq.push_back(add);
            }

            while (!dq.empty() && dq.front() < i - r) {
                dq.pop_front();
            }

            if (!dq.empty()) {
                bestOne = max(bestOne, pref[i] - pref[dq.front()]);
            }
        }

        State zeroPenalty = solve(0);

        if (zeroPenalty.cnt <= m) {
            if (zeroPenalty.cnt > 0) return zeroPenalty.val;
            return bestOne;
        }

        long long low = 0, high = 400000000000000LL;

        while (low < high) {
            long long mid = (low + high) / 2;

            State res = solve(mid);

            if (res.cnt > m) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        State res = solve(low);

        return max(bestOne, res.val + low * m);
    }
};