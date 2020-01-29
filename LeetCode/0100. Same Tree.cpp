// Time  : 0 ms (100.00%)
// Memory: 10.2 MB (5.31%)

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