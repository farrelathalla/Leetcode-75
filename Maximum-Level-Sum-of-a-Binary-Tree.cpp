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
    void recSum(TreeNode* root, unordered_map<int, long long>& sum, int height) {
        if (!root) return;
        sum[height] += root->val;
        recSum(root->left, sum, height + 1);
        recSum(root->right, sum, height + 1);
    }
    int maxLevelSum(TreeNode* root) {
        unordered_map<int, long long> sum;
        recSum(root, sum, 1);
        long long max = LLONG_MIN;
        int level = 0;
        for (auto& [key, val] : sum) {
            if (val == max) {
                if (key < level) {
                    level = key;
                }
            }
            else if (val > max) {
                max = val;
                level = key;
            }
        }
        return level;
    }
};