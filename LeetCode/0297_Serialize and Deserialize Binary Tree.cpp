// Time  : 48 ms (70.66%)
// Memory: 32.1 MB (32.90%)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return dfs1(root) + " ";
    }

    string dfs1(TreeNode *root) {
        if (root == nullptr) return "";
        return to_string(root->val) + " " + dfs1(root->left) + " " + dfs1(root->right);
    }

    TreeNode* dfs2(const string &data, int &n) {
        int length = 0, value = 0, sign = 1;
        while (data[n] != ' ') {
            if (data[n] == '-') sign *= -1;
            else value = value * 10 + data[n] - '0';
            ++n;
            ++length;
        }
        ++n;
        if (length == 0) {
            return nullptr;
        }
        TreeNode *here = new TreeNode(value * sign);
        here->left = dfs2(data, n);
        here->right = dfs2(data, n);
        return here;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = 0;
        return dfs2(data, n);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));