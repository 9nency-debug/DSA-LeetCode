class Solution {
public:
    bool checkDivisibility(int n) {
        long long org = n, sum = 0, product = 1;
        while(n > 0){
            int digit = n % 10;
            sum += digit;
            product *= digit;
            n /= 10;
        }
        return org % (sum + product) == 0;
    }
};