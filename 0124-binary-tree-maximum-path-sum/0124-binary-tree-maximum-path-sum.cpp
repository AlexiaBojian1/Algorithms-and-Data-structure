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
    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        dfs(root,maxsum);
        return maxsum;
    }
    int dfs(TreeNode* root, int& maxsum) {
        if(root == nullptr) {
            return 0;
        }
        int left= max(dfs(root->left,maxsum),0);
        int right = max(dfs(root->right,maxsum),0);
        int curr = root->val+left+right;
        maxsum = max(maxsum,curr);
        return root->val + max(left ,right);
    }
};