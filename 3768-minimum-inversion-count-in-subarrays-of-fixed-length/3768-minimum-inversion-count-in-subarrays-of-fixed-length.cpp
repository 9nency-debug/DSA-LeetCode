class Solution {
public:
    long long minInversionCount(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> comp = nums;
        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());
        auto get = [&](int x){
            return lower_bound(comp.begin(), comp.end(), x) - comp.begin() + 1;
        };
        int m = comp.size();
        struct Fenwick {
            int size;
            vector<long long> bit;
            Fenwick(int n): size(n), bit(n+1,0) {}
            void update(int i, int val){
                while(i <= size){
                    bit[i] += val;
                    i += (i & -i);
                }
            }
            long long query(int i){
                long long s = 0;
                while(i > 0){
                    s += bit[i];
                    i -= (i & -i);
                }
                return s;
            }
            long long range(int l, int r){
                return query(r) - query(l-1);
            }
        };
        Fenwick bit(m);
        long long inv = 0;
        long long ans = LLONG_MAX;
        for(int i = 0; i < k; i++){
            int x = get(nums[i]);
            inv += bit.range(x+1, m);
            bit.update(x, 1);
        }
        ans = min(ans, inv);
        for(int i = k; i < n; i++){
            int add = get(nums[i]);
            int remove = get(nums[i-k]);
            inv -= bit.range(1, remove-1);
            bit.update(remove, -1);
            inv += bit.range(add+1, m);
            bit.update(add, 1);   
            ans = min(ans, inv);
        }
        return ans;
    }
};