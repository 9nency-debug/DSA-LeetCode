class Solution {
public:
string smallestPalindrome(string s, int k) {
    auto comb = [](int n, int r, long long limit) {
        if (r > n)
            return 0LL;
        r = min(r, n - r);
        long long ans = 1;
        for (int i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;
            if (ans >= limit)
                return limit;
        }
        return ans;
    };
    auto countPerms = [&comb](const vector<int>& cnt,int len, long long limit) {
        long long perms = 1;
        int remaining = len;
        for (int x : cnt) {
            long long ways = comb(remaining, x, limit);
            perms *= ways;
            if (perms >= limit)
                return limit;
            remaining -= x;
        }
        return perms;
    };
    long long LIMIT = k + 1LL;
    vector<int> freq(26, 0);
    for (char c : s)
        freq[c - 'a']++;
    string middle = "";
    vector<int> half(26, 0);
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2)
            middle = char('a' + i);
        half[i] = freq[i] / 2;
    }
    int halfLen = 0;
    for (int x : half)
        halfLen += x;
    long long total = countPerms(half,halfLen,LIMIT);
    if (k > total)
        return "";
    string firstHalf = "";
    for (int pos = 0;
         pos < halfLen;
         pos++) {
        for (int c = 0;
             c < 26;
             c++) {
            if (half[c] == 0) continue;
            half[c]--;
            long long ways =
                countPerms(half,halfLen - pos - 1,LIMIT);
            if (k > ways) {
                k -= ways;
                half[c]++;
            } else {
                firstHalf +=
                    char('a' + c);
                break;
            }
        }
    }
    string result = firstHalf + middle;
    for (int i = firstHalf.size() - 1; i >= 0; i--) {
        result += firstHalf[i];
    }
    return result;
}
};