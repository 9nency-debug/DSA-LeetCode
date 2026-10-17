class Solution {
    private:
    static int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end(), [](int a, int b) {
            int sumA = getDigitSum(a);
            int sumB = getDigitSum(b);
            if (sumA != sumB) {
                return sumA < sumB;
            }
            return a < b;
        });
        unordered_map<int, int> numToIndex;
        for(int i = 0; i < n; ++i) {
            numToIndex[sortedNums[i]] = i;
        }
        unordered_set<int> seen;
        int totalSwaps = 0;
        for (int i = 0; i < n; ++i){
            if(seen.count(i) || numToIndex[nums[i]] == i) {continue;}
            int cycleSize = 0;
            int j = i;
            while (!seen.count(j)) {
                seen.insert(j);
                j = numToIndex[nums[j]];
                ++cycleSize;
            }
            if (cycleSize > 1) {
                totalSwaps += (cycleSize - 1);
            }
        }
        
        return totalSwaps;
    }
};
