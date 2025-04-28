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

 bool isBalncedHelper(TreeNode* root, int& height) {
    if(root == nullptr) {
        height = -1;
        return true;
    }

    int left;
    int right;
    if(isBalncedHelper(root->left, left) && isBalncedHelper(root->right, right) && abs(left - right) < 2) {
        height = max(right, left) + 1;
        return true;

    }

    return false;
 }   
public:
    bool isBalanced(TreeNode* root) {
        int height;
        return isBalncedHelper(root, height);
    }
};