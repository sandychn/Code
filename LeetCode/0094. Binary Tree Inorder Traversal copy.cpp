// Time  : 0 ms (100.00%)
// Memory: 9.5 MB (14.60%)

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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;

        TreeNode* p = root;

        while (p != nullptr || !st.empty()) {
            while (p != nullptr) {
                st.push(p);
                p = p->left;
            }
            p = st.top();
            st.pop();
            result.push_back(p->val);
            p = p->right;
        }
        
        return result;
    }
};