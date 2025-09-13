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

    int dfs(TreeNode* node, int maxsofar) {
        if(node == nullptr) {
            return 0;
        }

        int left = dfs(node -> left, max(maxsofar, node -> val));
        int right = dfs(node -> right, max(maxsofar, node -> val));
        int ans = left + right;

        if(node -> val >= maxsofar) {
            ans++;
        }

        return ans;

    }
};