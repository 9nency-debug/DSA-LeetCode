#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = static_cast<int>(nums.size());
        if (n == 0) return -1;

        vector<int> prefixMax(n), suffixMin(n);
        prefixMax[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        }

        suffixMin[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i + 1], nums[i]);
        }

        for (int i = 0; i < n; i++) {
            long long diff = 1LL * prefixMax[i] - suffixMin[i];
            if (diff <= k) {
                return i;
            }
        }

        return -1;
    }
};
