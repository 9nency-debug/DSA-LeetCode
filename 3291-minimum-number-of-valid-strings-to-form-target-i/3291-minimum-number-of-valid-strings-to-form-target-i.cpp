typedef long long ll;

class RH {
    static const ll P1 = 31;
    static const ll P2 = 37;
    static const ll M1 = 1000000007;
    static const ll M2 = 1000000009;
    vector<ll> h1, h2, p1, p2;
public:
    RH(string& s) {
        int n = s.size();
        h1.resize(n + 1, 0);
        h2.resize(n + 1, 0);
        p1.resize(n + 1, 1);
        p2.resize(n + 1, 1);
        for (int i = 0; i < n; ++i) {
            ll x = s[i] - 'a' + 1;
            h1[i + 1] = (h1[i] * P1 + x) % M1;
            h2[i + 1] = (h2[i] * P2 + x) % M2;
            p1[i + 1] = (p1[i] * P1) % M1;
            p2[i + 1] = (p2[i] * P2) % M2;
        }
    }
    ll get(ll l, ll r) {
        ll x1 = (h1[r + 1] - h1[l] * p1[r - l + 1] % M1 + M1) % M1;
        ll x2 = (h2[r + 1] - h2[l] * p2[r - l + 1] % M2 + M2) % M2;
        return x1 * M2 + x2;
    }
};
class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        unordered_set<ll> st;
        for (auto it : words) {
            RH rh(it);
            for (int i = 0; i < it.size(); ++i) {
                st.insert(rh.get(0, i));
            }
        }
        int n = target.size();
        vector<ll> dp(n + 1, 1e9);
        dp[n] = 0;
        RH rh(target);
        for (int i = n - 1; i >= 0; --i) {
            if (st.count(rh.get(i, n - 1))) {
                dp[i] = 1;
                continue;
            }
            for (int j = i; j < n; ++j) {
                if (st.count(rh.get(i, j))) {
                    dp[i] = min(dp[i], dp[j + 1] + 1);
                } else {
                    break;
                }
            }
        }
        return dp[0] == 1e9 ? -1 : dp[0];
    }
};

// Double Roulling Hash & DP