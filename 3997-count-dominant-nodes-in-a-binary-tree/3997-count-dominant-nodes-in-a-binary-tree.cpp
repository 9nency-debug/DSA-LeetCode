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
int cnt=0;
int dfs(TreeNode* r){
    if(!r)return 0;
    int l=dfs(r->left);
    int rr=dfs(r->right);
    if(r->val>=max(l,rr))cnt++; // current node is maximum in its subtree
    return max({r->val,l,rr}); // return subtree maximum
}
    int countDominantNodes(TreeNode* root) {
        dfs(root);
        return cnt;
    }
};