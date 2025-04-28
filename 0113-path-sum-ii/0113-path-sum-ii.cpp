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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, targetSum, path, res);
        return res;
    }

    void dfs(TreeNode* node, int remaining, vector<int>& path, vector<vector<int>>& res) {
        if(node == nullptr) {
            return;
        }

        path.push_back(node->val);
        remaining -= node->val;
        if(node->left == nullptr && node->right ==nullptr) {
            if(remaining == 0){
                res.push_back(path);
            }
        } else {
            dfs(node->left,  remaining, path, res);
            dfs(node->right, remaining, path, res);
        }
        path.pop_back();
       
    }
};