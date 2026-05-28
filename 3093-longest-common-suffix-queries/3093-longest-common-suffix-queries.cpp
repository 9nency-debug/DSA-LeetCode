class Solution {
    struct Node {
        int children[26];
        int bestIndex;
        int minLength;
        Node() {
            for (int i = 0; i < 26; ++i) children[i] = -1;
            bestIndex = -1;
            minLength = 1e9;
        }
    };
    vector<Node> trie;
public:
    void insert(const string& word, int wordIdx) {
        int n = word.length();
        int curr = 0;
        auto update = [&](int nodeIdx) {
            if (n < trie[nodeIdx].minLength) {
                trie[nodeIdx].minLength = n;
                trie[nodeIdx].bestIndex = wordIdx;
            }
        };
        update(curr);
        for (int i = n - 1; i >= 0; --i) {
            int c = word[i] - 'a';
            if (trie[curr].children[c] == -1) {
                trie[curr].children[c] = trie.size();
                trie.emplace_back();
            }
            curr = trie[curr].children[c];
            update(curr);
        }
    }
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        trie.clear();
        trie.emplace_back();
        for (int i = 0; i < wordsContainer.size(); ++i) {
            insert(wordsContainer[i], i);
        }
        vector<int> ans;
        for (const string& q : wordsQuery) {
            int curr = 0;
            int res = trie[0].bestIndex;
            for (int i = q.length() - 1; i >= 0; --i) {
                int c = q[i] - 'a';
                if (trie[curr].children[c] != -1) {
                    curr = trie[curr].children[c];
                    res = trie[curr].bestIndex;
                } else {
                    break;
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};