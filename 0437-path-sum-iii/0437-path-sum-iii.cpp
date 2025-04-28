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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> freq;
        long long target = targetSum;
        freq[0] = 1;
        return dfs(root, 0LL, target, freq);
    }

    int dfs(TreeNode* node, long long curr, long long target, unordered_map<long long, int>& freq) {
        if(!node) {
            return 0;
        }
        curr += node->val;
        int pathshere = freq[curr - target];
        freq[curr]++;

        pathshere += dfs(node->left, curr, target, freq);
        pathshere += dfs(node->right, curr, target, freq);
        freq[curr]--;
        return pathshere;


    }
};