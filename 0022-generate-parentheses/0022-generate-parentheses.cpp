class Solution {
public:
vector<string> res;
void f(int a, int b, int p, string &s) {
    if(a==0 && b==0) {
        res.push_back(s);
        return;
        }
        if(a) {
            s.push_back('(');
            f(a-1, b, p+1, s);
            s.pop_back();
        }
        if(b) {
            if(p) {
                s.push_back(')');
                f(a, b-1, p-1, s);
                s.pop_back();
            }
        }
}
    vector<string> generateParenthesis(int n) {
        string s;
        f(n, n, 0, s);
        return res;
    }
};
