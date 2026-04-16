#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        vector<int> ans(n, INT_MAX);

        for (auto &it : mp) {
            vector<int> &v = it.second;
            int k = v.size();
            if (k == 1) continue;
            for (int i = 0; i < k; i++) {
                int curr = v[i];
                int prev = v[(i - 1 + k) % k];
                int next = v[(i + 1) % k];

                int d1 = abs(curr - prev);
                int d2 = abs(curr - next);

                d1 = min(d1, n - d1);
                d2 = min(d2, n - d2);

                ans[curr] = min(d1, d2);
            }
        }
        vector<int> res;
        for (int q : queries) {
            if (ans[q] == INT_MAX) res.push_back(-1);
            else res.push_back(ans[q]);
        }

        return res;
    }
};
int main() {
    
}