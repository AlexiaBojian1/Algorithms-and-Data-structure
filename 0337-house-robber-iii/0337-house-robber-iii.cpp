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
    int rob(TreeNode* root) {
        auto[robRoot , skipRoot] = dfs(root);
        return max(robRoot, skipRoot);
    }

    pair<int, int> dfs(TreeNode* node) {
        if(!node) {
            return {0,0};
        }

        auto[leftRob, leftSkip] = dfs(node->left);
        auto[rightRob, rightSkip] = dfs(node->right);

        int robThis = node->val + leftSkip + rightSkip;
        int skipThis = max(leftRob, leftSkip) + max(rightRob ,rightSkip);
        return {robThis, skipThis};
    }
};