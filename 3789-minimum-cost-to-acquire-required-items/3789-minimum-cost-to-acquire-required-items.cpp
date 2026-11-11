class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,int need1, int need2) {
        long long common = min(need1, need2);
        long long extra1 = max(0, need1 - need2);
        long long extra2 = max(0, need2 - need1);
        long long commonCost = common * min(1LL * costBoth,1LL * cost1 + cost2);
        long long extraCost1 = extra1 * min(cost1, costBoth);
        long long extraCost2 = extra2 * min(cost2, costBoth);
        return commonCost + extraCost1 + extraCost2;
    }
};
