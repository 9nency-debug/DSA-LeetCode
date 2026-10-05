class Solution {
public:
    int scoreOfParentheses(string& s) {
        int score=0, b=0, p=0;
        for(char c: s){
            if (c=='('){
                b++;
                p=1;
            } else {
                b--;
                score+=p<<b;
                p=0;
            }
        }
        return score;
    }
};