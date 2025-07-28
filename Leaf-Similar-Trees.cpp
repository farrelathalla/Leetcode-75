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
    void dfs(TreeNode* root, vector<int>& leaf) {
        if (root->left && root->right) {
            dfs(root->left, leaf);
            dfs(root->right, leaf);
        } else if (root->left) {
            dfs(root->left, leaf);
        } else if (root->right) {
            dfs(root->right, leaf);
        } else {
            leaf.push_back(root->val);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> val1;
        vector<int> val2;
        if (root1) dfs(root1, val1);
        if (root2) dfs(root2, val2);
        return val1 == val2;
    }
};