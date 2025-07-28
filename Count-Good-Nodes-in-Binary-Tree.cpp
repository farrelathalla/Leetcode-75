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
    int good(TreeNode* root, int max) {
        int count = 0;
        if (root->left && root->right) {
            if (root->left->val >= max) {
                count++;
                count += good(root->left, root->left->val);
            } else {
                count += good(root->left, max);
            }
            if (root->right->val >= max) {
                count++;
                count += good(root->right, root->right->val);
            } else {
                count += good(root->right, max);
            }
        } else if (root->left) {
            if (root->left->val >= max) {
                count++;
                count += good(root->left, root->left->val);
            } else {
                count += good(root->left, max);
            }
        } else if (root->right) {
            if (root->right->val >= max) {
                count++;
                count += good(root->right, root->right->val);
            } else {
                count += good(root->right, max);
            }
        }
        return count;
    }
    int goodNodes(TreeNode* root) {
        return good(root, root->val)+1;
    }
};