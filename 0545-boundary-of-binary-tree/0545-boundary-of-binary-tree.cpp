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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(!root) return {};
        if(!root->left && !root->right) {
            return {root->val};
        }
        vector<int> ans;
        ans.push_back(root->val);
        addLeft(root->left, ans);
        addLeaves(root, ans);
        addRight(root->right,ans);
        return ans;
    }
private:
    void addLeft(TreeNode* node, vector<int>& out) {
        while(node) {
            if(!isLeaf(node)) out.push_back(node->val);
            node = (node->left) ? node->left : node->right;
        }
    }

    void addRight(TreeNode* node, vector<int>& out) {
        vector<int> stk;
        while(node){
            if(!isLeaf(node)) stk.push_back(node->val);
            node = (node->right) ? node->right : node->left;
        }
        for(int i = stk.size() - 1; i >= 0; i--) {
            out.push_back(stk[i]);
        }
    }

    void addLeaves(TreeNode* node, vector<int>& out) {
        if(!node) return;
        if(isLeaf(node)) {
            out.push_back(node->val);
            return;
        }
        addLeaves(node->left, out);
        addLeaves(node->right, out);
    }

    inline bool isLeaf(TreeNode* node){return node && !node->left && !node->right;}

};