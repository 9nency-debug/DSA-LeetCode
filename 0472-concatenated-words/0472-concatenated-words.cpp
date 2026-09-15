class Solution {
public:
    class TrieNode{
        public : 
            char node;
            TrieNode *childs[26];
            bool isTerminal;
            TrieNode(char ch){
                node = ch;
                for(int i = 0 ; i < 26 ; i++) childs[i] = NULL;
                isTerminal = false;
            }
    };
    class Trie{
        public:
            TrieNode *root;
            Trie(){
                root = new TrieNode('1');
            }
            void InsertWord(string word){
                TrieNode * curr = root;
                for(int i = 0 ; i < word.size() ; i++){
                    int ind = word[i] - 'a';
                    if(curr -> childs[ind] == NULL){
                        curr -> childs[ind] = new TrieNode(word[i]);
                    }
                    curr = curr -> childs[ind];
                }
                curr -> isTerminal = true;
            }
    };
    bool memo(string &words, int n, TrieNode *curr, TrieNode *root, int i, int cnt, vector<int>&dp){
        bool freshStart = (root == curr);
        if(dp[i] != -1 and freshStart) return dp[i]; 
        int ind = words[i] - 'a';
        if(curr == root){
            curr = curr -> childs[ind];
        }
        if(i == n - 1){
            if(curr and curr -> isTerminal == true and cnt){
                return true;
            }
            return false;
        }
        bool ans = false;
        if(curr and curr -> isTerminal) ans |= memo(words, n, root, root, i + 1, cnt + 1, dp);
        if(curr) ans |= memo(words, n, curr -> childs[words[i + 1] - 'a'], root, i + 1, cnt, dp);
        if(freshStart){
            dp[i] = ans;
        }
        return ans;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie t;
        for(auto word : words){
            t.InsertWord(word);
        }
        TrieNode *root = t.root;
        vector<string>ans;
        for(auto word : words){
            int n = word.size();
            TrieNode *curr = t.root;
            vector<int>dp(n + 1, -1);
            if(memo(word, n, curr, root, 0, 0, dp)){
                ans.push_back(word);
            }
        }
        return ans;
    }
};