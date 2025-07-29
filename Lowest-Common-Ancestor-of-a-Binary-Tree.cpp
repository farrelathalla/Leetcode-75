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
    bool foundRec(TreeNode* root, TreeNode* target) {
        if (!root) return false;
        if (root->val == target->val) return true;
        return (foundRec(root->left, target) || foundRec(root->right, target));
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool trueP = foundRec(root, p);
        bool trueQ = foundRec(root, q);
        if (trueP && trueQ) {
            if (foundRec(root->left, p) && foundRec(root->left, q)) {
                return lowestCommonAncestor(root->left, p, q);
            } else if (foundRec(root->right, p) && foundRec(root->right, q)) {
                return lowestCommonAncestor(root->right, p, q);
            } else {
                return root;
            }
        }
        return nullptr;
    }
};