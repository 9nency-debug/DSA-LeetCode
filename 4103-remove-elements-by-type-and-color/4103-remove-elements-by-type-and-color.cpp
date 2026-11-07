class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {
        stack<tuple<int, int, int>> st;
        int n = types.size();
        for(int i = 0; i < n; i++) {
            int t = types[i];
            int c = colors[i];
            if(!st.empty() && get<0>(st.top()) == t && get<1>(st.top()) == c) {
                int cnt = get<2>(st.top()) + 1;
                st.pop();
                if(cnt <groupSize[t]) {
                    st.push({t, c, cnt});
                }
            } else {
                if(groupSize[t] == 1) continue;
                    st.push({t, c, 1});
            }
        }
        return st.empty();
    }
};