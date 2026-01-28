#include <iostream>
#include <stack>
#include <string>
#include <cctype> // for isdigit and other character funtions
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int result = 0;
        int num = 0;
        int sign = 1;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }
            else if (ch == '+' || ch == '-') {
                result += sign * num;
                num = 0;
                sign = (ch == '+') ? 1 : -1;
            }
            else if (ch == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            }
            else if (ch == ')') {
                result += sign * num;
                num = 0;

                int prevSign = st.top(); st.pop();
                int prevResult = st.top(); st.pop();

                result = prevResult + prevSign * result;
            }
        }

        result += sign * num;
        return result;
    }
};
