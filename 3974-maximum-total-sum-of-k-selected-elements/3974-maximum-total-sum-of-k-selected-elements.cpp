class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.rbegin(), nums.rend());
        vector<long long> factors;

        for(int i =0; i<k;i++){
            factors.push_back(max(1, mul-i));
            
        }
        long long ans =0;
        
        for(int i=0;i<k;i++){
            ans+=1LL *nums[i]*factors[i];
        }
        return ans;
    }
};