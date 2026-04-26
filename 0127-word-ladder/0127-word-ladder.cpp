class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
         unordered_set<string> dict(wordList.begin(), wordList.end());

        if (!dict.count(endWord)) return 0;

        queue<pair<string,int>> q;
        unordered_set<string> vis;

        q.push({beginWord, 1});
        vis.insert(beginWord);

        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            string word = front.first;
            int steps = front.second;

            if (word == endWord) 
            return steps;

            for (string next : wordList) {

                if (vis.count(next)) 
                continue;

                int diff = 0;
                for (int i = 0; i < word.size(); i++) {
                    if (word[i] != next[i]) diff++;
                }

                if (diff == 1) {
                    vis.insert(next);
                    q.push({next, steps + 1});
                }
            }
        }

        return 0;
    }
};