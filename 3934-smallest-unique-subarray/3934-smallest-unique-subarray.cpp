#define ll long long int  
class Solution {
public:
    const ll mod = 1e9 + 7;
    const ll p = 1e5 + 3;
    int smallestUniqueSubarray(vector<int>& nums) 
    {
        int n = nums.size();
        int l = 1, r = n;
        int ans;
        while(l <= r)
        {
            int i = (l + r)/2;
            ll curr = 0;
            ll highest_power = 1;
            for(int j = 0; j < i; j++)
            {   
                curr = (curr * p + nums[j])%mod;
                highest_power = (highest_power * p)%mod;

            }
            unordered_map<ll,ll> m;
            m[curr]++;
            int k = 1;
            for(int j = i; j < n; j++)
            {
                ll outgoing = (nums[j-i] * highest_power)%mod;
                curr = (curr * p + nums[j])%mod;
                curr = (curr - outgoing + mod)%mod;
                if(m.find(curr) == m.end())
                {
                    m[curr]++;
                    k++;
                }
                else  
                {
                    if(m[curr] == 1)
                        k--;
                    m[curr]++;

                }
            }
            if(k >= 1)
            {
                ans = i;
                r = i - 1;

            }
            else  
                l = i + 1;

        }
        return ans;
        
    }
};