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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return vector<int>{};
        queue<TreeNode*> queue;
        queue.push(root);
        vector<int> ans;
        while(!queue.empty()) {
            int number = queue.size();
            ans.push_back(queue.back() -> val);
            for(int i = 0; i < number; i++) {
                TreeNode* current = queue.front();
                queue.pop();
                if(current -> left) queue.push(current->left);
                if(current -> right) queue.push(current -> right); 
            }
        }
        return ans;
    }
};