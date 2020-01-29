#include "../LeetCode/leetcode_header.hpp"

class Solution {
   public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> pQueue, qQueue;
        pQueue.push(p);
        qQueue.push(q);
        while (!pQueue.empty() && !qQueue.empty()) {
            TreeNode* pFront = pQueue.front();
            TreeNode* qFront = qQueue.front();

            pQueue.pop();
            qQueue.pop();

            if (pFront == nullptr || qFront == nullptr) {
                if (!(pFront == nullptr && qFront == nullptr)) {
                    return false;
                }
            } else if (pFront->val != qFront->val) {
                return false;
            } else {
                pQueue.push(pFront->left);
                pQueue.push(pFront->right);
                qQueue.push(qFront->left);
                qQueue.push(qFront->right);
            }
        }
        return pQueue.empty() && qQueue.empty();
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* p = stringToTreeNode(line);
        getline(cin, line);
        TreeNode* q = stringToTreeNode(line);

        bool ret = Solution().isSameTree(p, q);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}