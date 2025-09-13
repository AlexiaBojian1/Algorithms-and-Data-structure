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

        if(root == nullptr) {
            return vector<int>{};
        }

        queue<TreeNode*> queue;
        vector<int> ans;
        queue.push(root);
        while(!queue.empty()) {

            int number = queue.size();
            ans.push_back(queue.back() -> val);

            for(int i = 0; i < number; i++) {
                TreeNode* node = queue.front();
                queue.pop();
                if(node -> left) {
                    queue.push(node -> left);
                }
                if(node -> right) {
                    queue.push(node -> right);
                }
            }
        }
        return ans;
    }
};