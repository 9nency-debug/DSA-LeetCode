class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        vector<int> dead(10000, 0);
        vector<int> vis(10000, 0);

        for (string s : deadends) {
            dead[stoi(s)] = 1;
        }

        if (dead[0]) 
        return -1;
        if (target == "0000") 
        return 0;

        queue<string> q;
        q.push("0000");
        vis[0] = 1;

        int moves = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string cur = q.front();
                q.pop();

                if (cur == target) 
                return moves;

                for (int i = 0; i < 4; i++) {
                    string next1 = cur;
                    next1[i] = (next1[i] == '9') ? '0' : next1[i] + 1;

                    int num1 = stoi(next1);
                    if (!dead[num1] && !vis[num1]) {
                        vis[num1] = 1;
                        q.push(next1);
                    }

                    string next2 = cur;
                    next2[i] = (next2[i] == '0') ? '9' : next2[i] - 1;
                    int num2 = stoi(next2);
                    if (!dead[num2] && !vis[num2]) {
                        vis[num2] = 1;
                        q.push(next2);
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};