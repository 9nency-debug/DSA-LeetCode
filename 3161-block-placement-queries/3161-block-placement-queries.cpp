class FenwickTree {
    vector<int> tree;
    int size;
public:
    FenwickTree(int n) {
        size = n;
        tree.assign(n + 1, 0);
    }

    void maximize(int i, int val) {
        while (i <= size) {
            tree[i] = max(tree[i], val);
            i += i & -i;
        }
    }

    int get_max(int i) {
        int res = 0;
        while (i > 0) {
            res = max(res, tree[i]);
            i -= i & -i;
        }
        return res;
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int max_range = min(50000, (int)queries.size() * 3);
        set<int> obstacles = {0, max_range};
        for (const auto& q : queries) {
            if (q[0] == 1) {
                obstacles.insert(q[1]);
            }
        }
        FenwickTree ft(max_range + 1);
        auto it = obstacles.begin();
        int prev_obs = *it;
        ++it;
        while (it != obstacles.end()) {
            int curr_obs = *it;
            ft.maximize(curr_obs, curr_obs - prev_obs);
            prev_obs = curr_obs;
            ++it;
        }
        vector<bool> answers;
        for (int i = queries.size() - 1; i >= 0; --i) {
            int type = queries[i][0];
            int x = queries[i][1];
            if (type == 1) {
                auto curr_it = obstacles.find(x);
                auto next_it = next(curr_it);
                auto prev_it = prev(curr_it);
                int next_obs = *next_it;
                int prev_obs = *prev_it;
                ft.maximize(next_obs, next_obs - prev_obs);
                obstacles.erase(curr_it);
            } else {
                int sz = queries[i][2];
                auto next_it = obstacles.upper_bound(x);
                int prev_obs = *prev(next_it);
                int max_gap = max(ft.get_max(prev_obs), x - prev_obs);       
                answers.push_back(max_gap >= sz);
            }
        }
        reverse(answers.begin(), answers.end());
        return answers;
    }
};