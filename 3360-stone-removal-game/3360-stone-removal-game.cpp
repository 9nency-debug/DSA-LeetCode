class Solution {
public:
    bool canAliceWin(int n) {
        bool turn = true;
        int num = 10;
        while (n >= num) {
            n -= num;
            num--;
            turn = !turn;
        }
        return !turn;
    }
};