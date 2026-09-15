class Solution {
public:
    struct TrieNode {
        TrieNode* children[26] = {NULL};
        int id = -1;
    };
    struct Trie {
    public:
        TrieNode* root;
        int idCounter;
        Trie() {
            root = new TrieNode();
            idCounter = 0;
        }
        ~Trie() { clear(root); }
        void clear(TrieNode* node) {
            if(!node) return;
            for(int i = 0; i < 26; i++) clear(node -> children[i]);
            delete node;
        }
        int insert(string& s) {
            TrieNode* node = root;
            for(char ch : s) {
                int idx = ch - 'a';
                if(!node -> children[idx]) {
                    node -> children[idx] = new TrieNode();
                }
                node = node -> children[idx];
            }
            if(node -> id == -1) node -> id = idCounter++;
            return node -> id;
        }
        TrieNode* getRoot() {return root;}
        int count() {return idCounter;}
    };
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        Trie trie; 
        for(string& s : original) trie.insert(s);
        for(string& s : changed) trie.insert(s);
        int n = trie.count();
        vector<vector<long long>> dist(n, vector<long long>(n, LLONG_MAX));
        for(int i = 0; i < n; i++) dist[i][i] = 0;
        for(int i = 0; i < original.size(); i++) {
            int u = trie.insert(original[i]); 
            int v = trie.insert(changed[i]);  
            dist[u][v] = min(dist[u][v], 1LL * cost[i]);
        }
        for(int via = 0; via < n; via++) {
            for(int start = 0; start < n; start++) {
                if(dist[start][via] == LLONG_MAX) continue;
                for(int end = 0; end < n; end++) {
                    if(dist[via][end] == LLONG_MAX) continue;
                    if(dist[start][end] > dist[start][via] + dist[via][end]) {
                        dist[start][end] = dist[start][via] + dist[via][end];
                    }
                }
            }
        }
        int m = source.length();
        vector<long long> dp(m + 1, LLONG_MAX);
        dp[0] = 0;
        for(int i = 0; i < m; i++) {
            if(dp[i] == LLONG_MAX) continue;
            if(source[i] == target[i]) dp[i + 1] = min(dp[i + 1], dp[i]);
            TrieNode* pS = trie.getRoot();
            TrieNode* pT = trie.getRoot();
            for(int j = i; j < m; j++) {
                int charS = source[j] - 'a';
                int charT = target[j] - 'a';
                pS = pS -> children[charS];
                pT = pT -> children[charT];
                if(!pT || !pS) break;
                if(pT -> id != -1 && pS -> id != -1) {
                    int u = pS -> id;
                    int v = pT -> id;
                    if(dist[u][v] == LLONG_MAX) continue;
                    dp[j + 1] = min(dp[j + 1], dp[i] + dist[u][v]); 
                }
            }
        }
        return dp[m] == LLONG_MAX ? -1 : dp[m];
    }
};