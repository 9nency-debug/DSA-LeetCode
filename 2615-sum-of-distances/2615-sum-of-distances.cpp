class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        vector<long long> res(n, 0);
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        for (auto &it : mp) {
            vector<int> &pos = it.second;
            int k = pos.size();

            vector<long long> prefix(k, 0);
            prefix[0] = pos[0];

            for (int i = 1; i < k; i++) {
                prefix[i] = prefix[i - 1] + pos[i];
            }

            for (int i = 0; i < k; i++) {
                long long left = pos[i] * 1LL * i - (i > 0 ? prefix[i - 1] : 0);
                long long right = (prefix[k - 1] - prefix[i]) - pos[i] * 1LL * (k - i - 1);
                res[pos[i]] = left + right;
            }
        }

        return res;
    }
};