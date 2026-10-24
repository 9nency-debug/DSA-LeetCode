class Solution {
public:
    int totalDay(vector<int>& tarik, int& mounth) {
        int sum = 0;
        for (int i = 0; i < mounth - 1; ++i) {
            sum += tarik[i];
        }
        return sum;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice,string arriveBob, string leaveBob) {
        vector<int> tarik{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int mounthAA = stoi(arriveAlice.substr(0, 2));
        int dateAA = stoi(arriveAlice.substr(3, 2));
        int countAA = totalDay(tarik, mounthAA) + dateAA;
        int mounthLA = stoi(leaveAlice.substr(0, 2));
        int dateLA = stoi(leaveAlice.substr(3, 2));
        int countLA = totalDay(tarik, mounthLA) + dateLA;
        int mounthBA = stoi(arriveBob.substr(0, 2));
        int dateBA = stoi(arriveBob.substr(3, 2));
        int countBA = totalDay(tarik, mounthBA) + dateBA;
        int mounthBL = stoi(leaveBob.substr(0, 2));
        int dateBL = stoi(leaveBob.substr(3, 2));
        int countBL = totalDay(tarik, mounthBL) + dateBL;
        int count = 0;
        for (int i = countAA; i <= countLA; ++i) {
            for (int j = countBA; j <= countBL; ++j) {
                if (i == j) {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};