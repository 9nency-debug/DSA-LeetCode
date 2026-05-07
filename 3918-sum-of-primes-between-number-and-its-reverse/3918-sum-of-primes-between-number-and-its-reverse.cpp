class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) 
        return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                return false;
            }
        }

        return true;
    }

    int sumOfPrimesInRange(int n) {
        int rev = 0, temp = n;

        while (temp > 0) {
            rev = rev * 10 + (temp % 10);
            temp /= 10;
        }

        int left = min(n, rev);
        int right = max(n, rev);
        int sum = 0;

        for (int i = left; i <= right; i++) {
            if (isPrime(i)) {
                sum += i;
            }
        }

        return sum;
    }
};