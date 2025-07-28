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
    int dfs(TreeNode* root, long long sum, unordered_map<long long, int>& prefs, int target) {
        if (!root) return 0;
        sum += root->val;
        int count = 0;
        if (prefs.count(sum-target)) {
            count += prefs[sum-target];
        }
        prefs[sum]++;
        count += dfs(root->left, sum, prefs, target);
        count += dfs(root->right, sum, prefs, target);
        prefs[sum]--;
        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefs;
        prefs[0] = 1;
        int count = dfs(root, 0, prefs, targetSum);
        return count;
    }
};