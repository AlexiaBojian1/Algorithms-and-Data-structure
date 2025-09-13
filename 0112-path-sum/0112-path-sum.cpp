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
    int target;
    bool hasPathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        return dfs(root, 0);
    }

    bool dfs( TreeNode* root, int curr) {
        if(root == nullptr) {
            return 0;
        }

        if(root -> right == nullptr && root -> left == nullptr) {
            return ( curr + root -> val == target);
        }
         
        curr = curr + root -> val;

        bool left = dfs(root -> left, curr);
        bool right = dfs(root -> right, curr);

        return left || right;


    }
};