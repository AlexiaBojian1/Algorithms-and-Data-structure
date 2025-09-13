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
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }

    int dfs(TreeNode* node, int maxi) {
        if(node == nullptr) {
            return 0;
        }

        int left = dfs(node -> left, max(maxi, node -> val));
        int right = dfs(node ->right, max(maxi, node -> val));
        int ans = left + right;

        if(node -> val >= maxi) {
            ans++;
        }
        return ans;

    }
};