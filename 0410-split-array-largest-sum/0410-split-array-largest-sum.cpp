class Solution {
public:
    bool canPartition(vector<int>& arr, long long maxSum, long long maxPartitions) {
        long long partitions = 1;
        long long curSum = 0;
        for (int a : arr) {
            if (a > maxSum) {
                return false;
            }
            if (a + curSum <= maxSum) {
                curSum += a;
            } else {
                partitions++;
                curSum = a;
                if (partitions > maxPartitions) {
                    return false;
                }
            }
        }
        return partitions <= maxPartitions;
    }
    int splitArray(vector<int>& nums, int k) {
        long long totalSum = 0, maxEl = 0;
        for (long long num : nums) {
            maxEl = max(maxEl, num);
            totalSum += num;
        }
        long long l = maxEl - 1, r = totalSum;
        while (l + 1 < r) {
            long long mid = l + (r - l) / 2;
            if (canPartition(nums, mid, k)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return r;
    }
};