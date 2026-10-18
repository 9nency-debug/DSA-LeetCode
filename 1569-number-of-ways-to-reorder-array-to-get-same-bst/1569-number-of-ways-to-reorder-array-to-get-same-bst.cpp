/*
class Solution {
    struct Node {
        int val;
        Node *left, *right;
        Node(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    Node* insert(Node* root, int x) {
        if (!root) return new Node(x);
        if (x < root->val) root->left = insert(root->left, x);
        else root->right = insert(root->right, x);
        return root;
    }
    Node* buildTree(vector<int>& arr) {
        Node* root = nullptr;
        for (int x : arr)
            root = insert(root, x);
        return root;
    }
    bool sameTree(Node* a, Node* b){
        if (!a && !b) return true;
        if (!a || !b) return false;
        return a->val == b->val && sameTree(a->left, b->left) && sameTree(a->right, b->right);
    }
    void deleteTree(Node* root) {
        if (!root) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }

public:
    int numOfWays(vector<int>& nums) {
        Node* original = buildTree(nums);
        vector<int> p = nums;
        sort(p.begin(), p.end());
        long long count = 0;
        const int MOD = 1e9 + 7;
        do{Node* root = buildTree(p);
            if(sameTree(original, root)) count++;
            deleteTree(root);
        } while (next_permutation(p.begin(), p.end()));
        deleteTree(original);
        return (count - 1 + MOD) % MOD;
    }
};
*/

// TC: (n*n!+n!*n^2) [TLE]
// SC: O(n)

/*
class Solution {
    static const int MOD = 1e9 + 7;
    long long countInterleavings(int L, int R) {
        if (L == 0 || R == 0) return 1;
        long long takeLeft = countInterleavings(L - 1, R);
        long long takeRight = countInterleavings(L, R - 1);
        return (takeLeft + takeRight) % MOD;
    }
    long long solve(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;
        vector<int> left, right;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0]) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        long long leftWays = solve(left);
        long long rightWays = solve(right);
        long long interleavings = countInterleavings(left.size(), right.size());
        return interleavings * leftWays % MOD * rightWays % MOD;
    }
public:
    int numOfWays(vector<int>& nums) {
        return (solve(nums) - 1 + MOD) % MOD;
    }
};
*/

// TC: O(n*2^n) [TLE]

class Solution {
    static const int MOD = 1e9 + 7;
    vector<vector<long long>> comb;
    long long solve(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;
        vector<int> left, right;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }
        long long leftWays = solve(left);
        long long rightWays = solve(right);
        int L = left.size();
        int R = right.size();
        return comb[L + R][L] * leftWays % MOD* rightWays % MOD;
    }
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        comb.assign(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; i++) {
            comb[i][0] = comb[i][i] = 1;
            for (int j = 1; j < i; j++) {
                comb[i][j] =(comb[i - 1][j - 1] +comb[i - 1][j]) % MOD;
            }
        }
        return (solve(nums) - 1 + MOD) % MOD;
    }
};

//TC: O(N^2) SC: O(N^2)