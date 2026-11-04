class Solution {
public:
    long long minOperations(const vector<int>& nums, int x, int k) {
        const int N = nums.size() - x + 1;
        vector<long long> beg_2_median_abs_deviation(N);
        SlidingMedianAbsDev smad(nums.begin(), nums.begin() + x);
        beg_2_median_abs_deviation[0] = smad.get_median_abs_deviation();
        for (int i = 1; i < N; ++i) {
            smad.replace(nums[i + x - 1], nums[i - 1]);
            beg_2_median_abs_deviation[i] = smad.get_median_abs_deviation();
        }
        vector<long long> dp(N), up(N);
        dp.back() = beg_2_median_abs_deviation.back();
        for (int j = N - 2; ~j; --j)
            dp[j] = min(dp[j + 1], beg_2_median_abs_deviation[j]);
        for (int i = 2; i <= k; ++i) {
            for (int j = N - 1; ~j; --j)
                up[j] = min(
                    j + 1 < N ? up[j + 1] : kInf,
                    j + x < N ? dp[j + x] + beg_2_median_abs_deviation[j] : kInf);
                    swap(dp, up);
        }
        val2count_a.offset += nums.size() + 1;
        val2count_b.offset += nums.size() + 1;
        return dp[0];
    }

private:
    static constexpr long long kInf = numeric_limits<long long>::max() / 3;
    static constexpr int kMaxVal = 1e6;
    struct Val2CountBuf {
        int offset = 0;
        array<int, kMaxVal * 2 + 1> v2c{};
    };
    static Val2CountBuf val2count_a, val2count_b;
    template <typename PQT>
    struct RmCountingPrioQ {
        PQT pq;
        Val2CountBuf& val2rm;
        int size = 0;
        long long sum = 0;
        RmCountingPrioQ(Val2CountBuf& val2rm) : val2rm(val2rm) {}
        void push(int v) {
            int& rm_count = val2rm.v2c[v + kMaxVal];
            if (rm_count > val2rm.offset)
                --rm_count;
            else
                pq.push(v);
            ++size;
            sum += v;
        }
        void erase(int v) {
            int& rm_count = val2rm.v2c[v + kMaxVal];
            rm_count = max(rm_count, val2rm.offset) + 1;
            --size;
            sum -= v;
            garbage_collect();
        }
        int top() const { 
            return pq.top(); 
            }
        void garbage_collect() {
            while (pq.size()) {
                int t = pq.top();
                // auto it = val2rm.find(t);
                // if (it == val2rm.end() || it->second == 0)
                //     return;
                // if (0 == --it->second)
                //     val2rm.erase(it);
                int& rm_count = val2rm.v2c[t + kMaxVal];
                if (rm_count <= val2rm.offset)
                    return;
                --rm_count;
                pq.pop();
            }
        }
    };

    struct SlidingMedianAbsDev {
        RmCountingPrioQ<priority_queue<int, vector<int>, less<int>>> low_lt{val2count_a};
        RmCountingPrioQ<priority_queue<int, vector<int>, greater<int>>> hgh_gt{val2count_b};
        int low_lt_target_size = 0;
        template<typename ItT>
        SlidingMedianAbsDev(ItT beg, ItT end) {
            vector<int> tmp(beg, end);
            nth_element(tmp.begin(), tmp.begin() + distance(beg, end) / 2, tmp.end());
            low_lt_target_size = (tmp.size() + 1) / 2;
            ItT mid = tmp.begin() + low_lt_target_size;
            for (auto it = tmp.begin(); it != mid; ++it)
                low_lt.push(*it);
            for (auto it = mid; it != tmp.end(); ++it)
                hgh_gt.push(*it);
        }
        long long get_median_abs_deviation() const {
            long long median = low_lt.top();
            return hgh_gt.sum - (hgh_gt.size - low_lt.size) * median - low_lt.sum;
        }
        void replace(int add, int rem) {
            int old_median = low_lt.top();
            if (rem <= old_median)
                low_lt.erase(rem);
            else
                hgh_gt.erase(rem);
            if (add <= old_median)
                low_lt.push(add);
            else
                hgh_gt.push(add);
            while (low_lt.size < low_lt_target_size) {
                int v = hgh_gt.top();
                hgh_gt.erase(v);
                low_lt.push(v);
            }
            while (low_lt.size > low_lt_target_size) {
                int v = low_lt.top();
                low_lt.erase(v);
                hgh_gt.push(v);
            }

        }
    };
};
Solution::Val2CountBuf Solution::val2count_a{};
Solution::Val2CountBuf Solution::val2count_b{};