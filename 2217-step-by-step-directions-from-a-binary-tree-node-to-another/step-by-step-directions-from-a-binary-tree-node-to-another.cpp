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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string pathToStart, pathToDest;
        
        // 1. Find paths from root to start and dest
        findPath(root, startValue, pathToStart);
        findPath(root, destValue, pathToDest);

        // 2. Find the index where paths diverge (LCA boundary)
        int i = 0;
        while (i < pathToStart.size() && i < pathToDest.size() && pathToStart[i] == pathToDest[i]) {
            i++;
        }

        // 3. Build final path:
        //    - 'U' for remaining part of start path
        //    - suffix of dest path (downwards)
        string upMoves(pathToStart.size() - i, 'U');
        string downMoves = pathToDest.substr(i);
        
        return upMoves + downMoves;
    }

private:
    // Helper DFS to record path from root to target node.
    // path accumulates 'L' or 'R' as we go down.
    bool findPath(TreeNode* node, int target, string &path) {
        if (!node) return false;
        if (node->val == target) return true;

        path.push_back('L');
        if (findPath(node->left, target, path)) return true;
        path.pop_back();  // backtrack

        path.push_back('R');
        if (findPath(node->right, target, path)) return true;
        path.pop_back();  // backtrack

        return false;
    }
};