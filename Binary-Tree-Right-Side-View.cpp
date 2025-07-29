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
    int heightRight = 0;
    int heightLeft = 0;
    void rightRec (TreeNode* root, vector<int>& vec, int height) {
        int maxHeight = max(heightRight, height);
        if (!root) return;
        if (root->right) {
            if (height > heightRight) {
                heightRight = height;       
                vec.push_back(root->right->val);
            }
        } else if (root->left) {
            if (height > heightRight) {
                heightRight = height;
                vec.push_back(root->left->val);
            }
        }
        rightRec(root->right, vec, height + 1);
        rightRec(root->left, vec, height + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        ans.push_back(root->val);
        heightRight++;
        heightLeft++;
        rightRec(root, ans, 2);
        return ans;
    }
};