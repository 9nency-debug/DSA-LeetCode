class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<pair<int,int>> q;
        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            while (!q.empty() && q.front().first < i - k)
                q.pop_front();
            int best = 0;
            if (!q.empty())
                best = max(0, q.front().second);

            int cur = nums[i] + best;
            ans = max(ans, cur);

            while (!q.empty() && q.back().second <= cur)
                q.pop_back();

            q.push_back({i, cur});
        }

        return ans;
    }
};