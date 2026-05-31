class Solution {
public:
    long long maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        int m = INT_MAX;
        for (auto &x : items) m = min(m, x[1]);

        vector<int> freq(n + 1, 0);
        for (auto &x : items) freq[x[0]]++;

        vector<long long> deg(n);

        for (int f = 1; f <= n; f++) {
            long long cnt = 0;
            for (int mul = f; mul <= n; mul += f) {
                cnt += freq[mul];
            }
            deg[f - 1] = cnt;
        }

        vector<pair<int,long long>> deals;

        long long K = 2LL * m;

        for (auto &x : items) {
            int factor = x[0];
            int price = x[1];

            long long d = deg[factor - 1] - 1;

            if (d > 0 && price < K) {
                deals.push_back({price, d});
            }
        }

        sort(deals.begin(), deals.end());

        long long remain = budget;
        long long benefit = 0;

        for (auto &[cost, cnt] : deals) {
            long long take = min(cnt, remain / cost);

            benefit += take * (K - cost);
            remain -= take * cost;

            if (remain < cost) continue;
        }

        return (budget + benefit) / m;
    }
};