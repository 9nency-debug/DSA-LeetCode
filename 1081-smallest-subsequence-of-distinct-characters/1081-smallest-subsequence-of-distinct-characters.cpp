class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26, -1);
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        vector<bool> seen(26, false);
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (seen[c - 'a']) continue;

            while (!st.empty() &&
                   c < st.top() &&
                   last[st.top() - 'a'] > i) {
                seen[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            seen[c - 'a'] = true;
        }

        string ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
