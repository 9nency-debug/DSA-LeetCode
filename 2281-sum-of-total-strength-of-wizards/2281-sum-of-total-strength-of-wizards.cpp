// class Solution {
// public:
//     int totalStrength(vector<int>& strength) {
//         const int MOD = 1e9 + 7;
//         int n = strength.size();
        
//         vector<long long> prefix(n + 1, 0);
//         for (int i = 0; i < n; i++) {
//             prefix[i + 1] = (prefix[i] + strength[i]) % MOD;
//         }

//         vector<long long> prefix2(n + 2, 0);
//         for (int i = 0; i <= n; i++) {
//             prefix2[i + 1] = (prefix2[i] + prefix[i]) % MOD;
//         }

//         vector<int> left(n), right(n);
//         stack<int> st;

//         for (int i = 0; i < n; i++) {
//             while (!st.empty() && strength[st.top()] > strength[i])
//                 st.pop();
//             left[i] = st.empty() ? -1 : st.top();
//             st.push(i);
//         }

//         while (!st.empty()) 
//         st.pop();

//         for (int i = n - 1; i >= 0; i--) {
//             while (!st.empty() && strength[st.top()] >= strength[i])
//                 st.pop();
//             right[i] = st.empty() ? n : st.top();
//             st.push(i);
//         }

//         long long ans = 0;

//         for (int i = 0; i < n; i++) {
//             int l = left[i];
//             int r = right[i];

//             long long leftCount = i - l;
//             long long rightCount = r - i;

//             long long totalRight = (prefix2[r + 1] - prefix2[i + 1] + MOD) % MOD;
//             long long totalLeft = (prefix2[i + 1] - prefix2[l + 1] + MOD) % MOD;

//             long long contrib = (totalRight * leftCount % MOD -
//                                  totalLeft * rightCount % MOD + MOD) % MOD;

//             ans = (ans + strength[i] * contrib) % MOD;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int totalStrength(vector<int>& strength) {
        const int MOD = 1e9 + 7;
        int n = strength.size();

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = (prefix[i] + strength[i]) % MOD;
        }

        vector<long long> prefix2(n + 2, 0);
        for (int i = 0; i <= n; i++) {
            prefix2[i + 1] = (prefix2[i] + prefix[i]) % MOD;
        }

        vector<int> left(n), right(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && strength[st.top()] > strength[i])
                st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && strength[st.top()] >= strength[i])
                st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int l = left[i];
            int r = right[i];

            long long leftCount = i - l;
            long long rightCount = r - i;

            long long totalRight = (prefix2[r + 1] - prefix2[i + 1] + MOD) % MOD;
            long long totalLeft  = (prefix2[i + 1] - prefix2[l + 1] + MOD) % MOD;

            long long contrib =
                (totalRight * leftCount % MOD -
                 totalLeft * rightCount % MOD + MOD) % MOD;

            ans = (ans + strength[i] * contrib) % MOD;
        }

        return ans;
    }
};