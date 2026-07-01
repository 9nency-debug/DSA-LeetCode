/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
vector<TreeNode*> pathstore(TreeNode* root, TreeNode* node, vector<TreeNode*> path){
    if(root==NULL){
        return {};
    }
    path.push_back(root);
    if(root->val==node->val){
        return path;
    }
    if(root->val<node->val){
        return pathstore(root->right, node, path);
    }
    else{
        return pathstore(root->left,node,path);
    }
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        path1 = pathstore(root, p,path1);
        vector<TreeNode*> path2;
        path2 = pathstore(root, q,path2);
        TreeNode* ans = NULL;
        int i = 0;
        while (i < path1.size() && i < path2.size()) {
            if (path1[i] == path2[i])
                ans = path1[i];
            else
                break;
            i++;
        }
        return ans;
    }
};