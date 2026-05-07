class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<long long> costR(n - 1);
        vector<long long> costL(n);
        for (int i = 0; i < n - 1; i++) {
            long long rightDiff = nums[i + 1] - nums[i];
            bool rightIsClosest;
            if (i == 0) {
                rightIsClosest = true;
            } else {
                long long leftDiff = nums[i] - nums[i - 1];
                rightIsClosest = (rightDiff < leftDiff);
            }
            costR[i] = rightIsClosest ? 1 : rightDiff;
        }
        for (int i = 1; i < n; i++) {
            long long leftDiff = nums[i] - nums[i - 1];
            bool leftIsClosest;
            if (i == n - 1) {
                leftIsClosest = true;
            } else {
                long long rightDiff = nums[i + 1] - nums[i];
                leftIsClosest = (leftDiff <= rightDiff);
            }

            costL[i] = leftIsClosest ? 1 : leftDiff;
        }
        vector<long long> prefR(n, 0), prefL(n, 0);

        for (int i = 1; i < n; i++) {
            prefR[i] = prefR[i - 1] + costR[i - 1];
        }

        for (int i = 1; i < n; i++) {
            prefL[i] = prefL[i - 1] + costL[i];
        }

        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];
            long long res;
            if (l < r) {
                res = prefR[r] - prefR[l];
            } else {
                res = prefL[l] - prefL[r];
            }
            ans.push_back((int)res);
        }
        return ans;
    }
};