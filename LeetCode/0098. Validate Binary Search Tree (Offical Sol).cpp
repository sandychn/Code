// Time  : 8 ms (98.85%)
// Memory: 20.8 MB (16.96%)

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
    bool isValidBST(TreeNode* root) {
        long long last = LLONG_MIN;
        return inorderTraversal(last, root);
    }

    bool inorderTraversal(long long& last, TreeNode* root) {
        if (root != nullptr) {
            if (!inorderTraversal(last, root->left)) return false;
            if (root->val <= last) return false;
            last = root->val;
            if (!inorderTraversal(last, root->right)) return false;
        }
        return true;
    }
};
