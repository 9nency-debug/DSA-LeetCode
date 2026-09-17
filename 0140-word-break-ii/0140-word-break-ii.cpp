class TrieNode {
public:
    TrieNode* child[26];
    bool isEnd = false;
    TrieNode() {
        for (int i = 0; i < 26; i++)
            this->child[i] = NULL;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }
    void insert(string& word) {
        TrieNode* curr = root;
        for (char& ch : word) {
            int idx = ch - 'a';
            if (curr->child[idx] == NULL) {
                curr->child[idx] = new TrieNode();
            }
            curr = curr->child[idx];
        }
        curr->isEnd = true;
    }
    bool search(string& word) {
        TrieNode* curr = root;
        for (char& ch : word) {
            int idx = ch - 'a';
            if (curr->child[idx] == NULL)
                return false;
            curr = curr->child[idx];
        }
        return curr->isEnd;
    }
    bool startsWith(string& word) {
        TrieNode* curr = root;
        for (char& ch : word) {
            int idx = ch - 'a';
            if (curr->child[idx] == NULL)
                return false;
            curr = curr->child[idx];
        }
        return true;
    }
};
class Solution {
public:
    Trie t;
    vector<string> result;
    void solve(int i, string curr_s, string& curr_w, string& s) {
        if (i == s.size()) {
            if (curr_w.size()==0) {
                curr_s.pop_back();
                result.push_back(curr_s);
            }
            return;
        }
        curr_w += s[i];
        if (t.search(curr_w)) {
            string temp = "";
            solve(i + 1, curr_s + curr_w + " ", temp, s);
        }
        solve(i + 1, curr_s, curr_w, s);
        curr_w.pop_back();
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (string& curr : wordDict)
            t.insert(curr);
        string curr_w;
        solve(0, "", curr_w, s);
        return result;
    }
};