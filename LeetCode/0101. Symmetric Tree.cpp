// Time  : 4 ms (92.39%)
// Memory: 15.1 MB (5.52%)

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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            TreeNode* left;
            TreeNode* right;
            left = q.front();
            q.pop();
            right = q.front();
            if (left == nullptr && right == nullptr) continue;
            if (left == nullptr || right == nullptr) return false;
            if (left->val != right->val) return false;
            q.push(left->left), q.push(right->right);
            q.push(left->right), q.push(right->left);
        }
        return true;
    }
};
