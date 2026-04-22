class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        double a = sides[0], b = sides[1], c = sides[2];
        if (a + b <= c || a + c <= b || b + c <= a) {
            return {};
        }
        vector<double> tmp = {a, b, c};
        sort(tmp.begin(), tmp.end());
        double x = tmp[0], y = tmp[1], z = tmp[2];

        double lhs = z * z;
        double rhs = x * x + y * y;
        auto clamp = [](double v) {
            return max(-1.0, min(1.0, v));
        };

        double A = acos(clamp((b*b + c*c - a*a) / (2*b*c))) * 180.0 / M_PI;
        double B = acos(clamp((a*a + c*c - b*b) / (2*a*c))) * 180.0 / M_PI;
        double C = acos(clamp((a*a + b*b - c*c) / (2*a*b))) * 180.0 / M_PI;
        vector<double> ans = {A, B, C};
        sort(ans.begin(), ans.end());

        return ans;
    }
};