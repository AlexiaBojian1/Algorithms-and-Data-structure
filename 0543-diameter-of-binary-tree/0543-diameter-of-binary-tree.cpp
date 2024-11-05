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
    int maxi = 0;
    int diameterOfBinaryTree(TreeNode* root) {
       longest(root);
       return maxi;
    }
    int longest(TreeNode* node) {
         if(node == nullptr) {
            return 0;
        }
        int left = longest(node->left);
        int right = longest(node->right);
        maxi = max(right+left, maxi);
        return max(right,left)+1;
    }
};