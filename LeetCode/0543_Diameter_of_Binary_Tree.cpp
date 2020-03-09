// Time  : 8 ms
// Memory: 22.7 MB

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        depth(ans, root);
        return ans;
    }

private:
    int depth(int& ans, TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int leftDepth = depth(ans, node->left);
        int rightDepth = depth(ans, node->right);
        ans = max(ans, leftDepth + 1 + rightDepth - 1);
        // (leftDepth + 1 + rightDepth) is the number of nodes.
        return 1 + max(leftDepth, rightDepth);
    }
};
