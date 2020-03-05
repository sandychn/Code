// Time  : 8 ms
// Memory: 23.2 MB

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (root != nullptr) {
            vector<int> temp;
            dfs(res, temp, 0, sum, root);
        }
        return res;
    }

private:
    void dfs(vector<vector<int>>& res, vector<int>& pathValues, int sum, const int goal, TreeNode* node) {
        pathValues.push_back(node->val);
        sum += node->val;
        if (node->left == nullptr && node->right == nullptr) {
            if (sum == goal) {
                res.push_back(pathValues);
            }
        } else {
            if (node->left != nullptr) {
                dfs(res, pathValues, sum, goal, node->left);
            }
            if (node->right != nullptr) {
                dfs(res, pathValues, sum, goal, node->right);
            }
        }
        pathValues.pop_back();
    }
};
