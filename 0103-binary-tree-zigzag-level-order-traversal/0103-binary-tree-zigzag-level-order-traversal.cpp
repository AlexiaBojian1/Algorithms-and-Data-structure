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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
           if (root == nullptr) {
        return vector<vector<int>> {};
    }
    
    queue<TreeNode*> q;
    q.push(root);
    vector<vector<int>> result;
    
    bool leftToRight = true;  // Use a boolean to decide the direction
    
    while (!q.empty()) {
        vector<int> levels;
        int nodes = q.size();
        for (int i = 0; i < nodes; i++) {
            TreeNode* node = q.front();
            q.pop();
            levels.push_back(node->val);
            
            // Always push left child first and then the right child
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        
        // If the current level is right-to-left, reverse the current level
        if (!leftToRight) {
            reverse(levels.begin(), levels.end());
        }
        
        result.push_back(levels);
        
        // Toggle the direction
        leftToRight = !leftToRight;
    }
    
    return result;

    }
};