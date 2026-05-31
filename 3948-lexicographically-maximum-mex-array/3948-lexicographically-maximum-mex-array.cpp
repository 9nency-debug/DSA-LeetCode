class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        int n = nums.size();

        vector<int> rem(n + 2, 0);
        for (int x : nums) {
            if (x <= n) rem[x]++;
        }

        int mex = 0;
        while (rem[mex] > 0) mex++;

        vector<int> ans;
        vector<int> seen(n + 2, 0);

        int i = 0;

        while (i < n) {
            int curMex = mex;

            if (curMex == 0) {
                ans.push_back(0);

                int x = nums[i++];
                if (x <= n) {
                    rem[x]--;
                    if (rem[x] == 0 && x < mex) {
                        mex = x;
                    }
                }
                continue;
            }

            int need = curMex;
            int j = i;

            while (need > 0) {
                int x = nums[j];

                if (x < curMex && seen[x] == 0) {
                    seen[x] = 1;
                    need--;
                }

                if (x <= n) {
                    rem[x]--;
                    if (rem[x] == 0 && x < mex) {
                        mex = x;
                    }
                }

                j++;
            }

            ans.push_back(curMex);

            for (int k = i; k < j; k++) {
                if (nums[k] < curMex) {
                    seen[nums[k]] = 0;
                }
            }

            while (rem[mex] > 0) mex++;

            i = j;
        }

        return ans;
    }
};