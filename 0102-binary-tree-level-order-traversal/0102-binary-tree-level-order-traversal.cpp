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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root ==nullptr) {
            return res;
        }
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()){
            int count = queue.size();
            vector<int> curr;
            for(int i = 0;i < count; i++) {
                TreeNode* node = queue.front();
                queue.pop();
                curr.push_back(node->val);
                if(node->left !=nullptr){
                    queue.push(node->left);
                }
                if(node->right != nullptr){
                    queue.push(node->right);
                }
            }
            res.push_back(curr);
        }
        return res;
    }
};