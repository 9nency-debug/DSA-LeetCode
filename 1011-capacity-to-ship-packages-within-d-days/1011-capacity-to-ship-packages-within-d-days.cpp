class Solution {
public:
    int ship(int ship_capacity, vector<int>& weights) {
        int n = weights.size();
        int days_taken = 0;
        int curr_weight = 0;
        for (int i = 0; i < n; i++) {
            if (curr_weight + weights[i] > ship_capacity) {
                days_taken++;
                curr_weight = weights[i];
            } else {
                curr_weight += weights[i];
            }
        }
        return days_taken + 1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int M = weights[0];
        int sum = weights[0];
        for (int i = 1; i < n; i++) {
            M = max(M, weights[i]);
            sum += weights[i];
        }
        int i = M;
        int j = sum;
        int min_capacity = sum;
        while (i <= j) {
            int ship_capacity = i + (j - i) / 2;
            int days_taken = ship(ship_capacity, weights);
            if (days_taken <= days) {
                min_capacity = ship_capacity;
                j = ship_capacity - 1;
            } else {
                i = ship_capacity + 1;
            }
        }
        return min_capacity;
    }
};