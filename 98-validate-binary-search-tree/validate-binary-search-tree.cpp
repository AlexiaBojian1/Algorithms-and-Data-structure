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
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN,LONG_MAX);
    }
    bool dfs(TreeNode* node, long small, long high) {
        if(node == nullptr) {
            return true;
        }
        if(node->val <= small || node->val >= high) {
            return false;
        }
         bool left = dfs(node->left, small, node->val);
         bool right = dfs(node->right, node->val, high);
         return left && right;
    }
};