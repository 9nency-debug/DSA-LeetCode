/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int, int> get(TreeNode* root) {
        if (!root) return {0, 0};
        auto left = get(root->left);
        auto right = get(root->right);
        return {
            root->val + left.first + right.first,
            1 + left.second + right.second
        };
    }

    int averageOfSubtree(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;
        auto left = get(root->left);
        auto right = get(root->right);
        int sum = root->val + left.first + right.first;
        int cnt = 1 + left.second + right.second;
        if (root->val == sum / cnt) ans++;
        ans += averageOfSubtree(root->left);
        ans += averageOfSubtree(root->right);
        return ans;
    }
};