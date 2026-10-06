class Solution {
public:
    int minAddToMakeValid(string s) {
        int minimum_Add = 0;
        int validate = 0;
        for(char ch : s) {
            if(ch == '(') {validate++;}
            else if(validate == 0) {minimum_Add++;}
            else validate--;
        }
        return (minimum_Add + validate);
    }
};