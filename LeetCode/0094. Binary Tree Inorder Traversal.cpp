// Time  : 0 ms (100.00%)
// Memory: 9.5 MB (14.28%)

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
        stack<pair<TreeNode*, bool>> st;
        vector<int> result;

        if (root != nullptr) {
            st.emplace(root, 0);
            while (!st.empty()) {
                auto top = st.top();
                st.pop();

                if (top.second) {
                    result.push_back(top.first->val);
                } else {
                    if (top.first->right != nullptr) {
                        st.emplace(top.first->right, false);
                    }
                    st.emplace(top.first, true);
                    if (top.first->left != nullptr) {
                        st.emplace(top.first->left, false);
                    }
                }
            }
        }
        
        return result;
    }
};