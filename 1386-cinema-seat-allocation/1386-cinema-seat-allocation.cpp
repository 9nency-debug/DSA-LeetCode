class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> mpp;
        for (auto &it : reservedSeats) {
            int row = it[0];
            int seat = it[1];
            mpp[row].insert(seat);
        }
        int count = 0;
        for (auto &it : mpp) {
            unordered_set<int> reserved = it.second;
            bool flag = true;
            if (!reserved.count(2) &&
                !reserved.count(3) &&
                !reserved.count(4) &&
                !reserved.count(5)) {
                count++;
            }
            else if (!reserved.count(4) &&
                     !reserved.count(5) &&
                     !reserved.count(6) &&
                     !reserved.count(7)) {
                count++;
                flag = false;
            }
            if (flag &&
                !reserved.count(6) &&
                !reserved.count(7) &&
                !reserved.count(8) &&
                !reserved.count(9)) {
                count++;
            }
        }
        count += 2 * (n - mpp.size());
        return count;
    }
};