class Solution {
public:
    int common(string &a, string &b) {
        int len = min(a.size(), b.size());
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            if (a[i] == b[i])
                cnt++;
            else
                break;
        }
        return cnt;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        vector<string> a, b;
        for (int x : arr1)
            a.push_back(to_string(x));
        for (int x : arr2)
            b.push_back(to_string(x));
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i = 0, j = 0;
        int ans = 0;
        while (i < a.size() && j < b.size()) {
            ans = max(ans, common(a[i], b[j]));
            if (a[i] < b[j])
                i++;
            else
                j++;
        }
        return ans;
    }
};