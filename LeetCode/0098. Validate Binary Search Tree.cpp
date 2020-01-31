// Time  : 8 ms (98.85%)
// Memory: 21.1 MB (5.27%)

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
   private:
    struct Node {
        int min, max;
        bool isBST;
    };

   public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        return dfs(root).isBST;
    }

    Node dfs(TreeNode* root) {
        int minVal = root->val;
        int maxVal = root->val;

        if (root->left != nullptr) {
            Node left = dfs(root->left);
            if (left.isBST && left.max < root->val) {
                minVal = min(minVal, left.min);
                maxVal = max(maxVal, left.max);
            } else {
                return {-1, -1, false};
            }
        }

        if (root->right != nullptr) {
            Node right = dfs(root->right);
            if (right.isBST && right.min > root->val) {
                minVal = min(minVal, right.min);
                maxVal = max(maxVal, right.max);
            } else {
                return {-1, -1, false};
            }
        }

        return {minVal, maxVal, true};
    }
};
