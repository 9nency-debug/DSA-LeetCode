class Solution {
public:
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n = nums.size();

        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }
        const long long NEG = LLONG_MIN / 4;
        vector<long long> prev(n + 1, 0), cur(n + 1, NEG);
        long long ans = NEG;
        for (int used = 1; used <= m; used++) {
            fill(cur.begin(), cur.end(), NEG);
            deque<int> dq;
            for (int i = 1; i <= n; i++) {
                cur[i] = cur[i - 1];
                int add = i - l;
                if (add >= 0 && prev[add] != NEG) {
                    long long val = prev[add] - pref[add];
                    while (!dq.empty()) {
                        int back = dq.back();
                        long long backVal = prev[back] - pref[back];
                        if (backVal <= val) dq.pop_back();
                        else break;
                    }
                    dq.push_back(add);
                }
                while (!dq.empty() && dq.front() < i - r) {
                    dq.pop_front();
                }
                if (!dq.empty()) {
                    int start = dq.front();
                    cur[i] = max(cur[i], pref[i] + prev[start] - pref[start]);
                }
            }
            ans = max(ans, cur[n]);
            prev.swap(cur);
        }
        return ans;
    }
};