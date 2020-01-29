// Time  : 8 ms (94.59%)
// Memory: 10 MB (22.82%)

class Solution {
   public:
    int minDeletionSize(vector<string>& A) {
        if (A.empty()) {
            return 0;
        }
        int len = A[0].size();
        int deleted = 0;
        queue<Node> q;
        q.emplace(0, A.size() - 1);
        queue<Node> backup = q;
        for (int currentCharId = 0; !q.empty() && currentCharId < len; ++currentCharId) {
            int cnt = q.size();
            bool thisColumnDeleted = false;
            while (cnt--) {
                const Node fnt = q.front();
                q.pop();

                bool flag = false;

                char pre = 0;
                for (int i = fnt.first; i <= fnt.last; i++) {
                    char ch = A[i][currentCharId];
                    if (pre > ch) {
                        flag = true;
                        break;
                    }
                    pre = ch;
                }

                if (flag) {
                    thisColumnDeleted = true;
                    ++deleted;
                    q = backup;
                    break;
                }

                Node changed(fnt.first, fnt.first);
                pre = A[fnt.first][currentCharId];
                for (int i = fnt.first; i <= fnt.last; i++) {
                    char ch = A[i][currentCharId];
                    if (pre < ch) {
                        changed.last = i - 1;
                        if (changed.first != changed.last) {
                            q.push(changed);
                        }
                        changed.first = changed.last = i;
                    } else if (pre == ch) {
                        changed.last = i;
                    }
                    pre = ch;
                }
                if (changed.first != changed.last) {
                    q.push(changed);
                }
            }
            if (!thisColumnDeleted) {
                backup = q;
            }
        }
        return deleted;
    }

   private:
    struct Node {
        int first, last;
        Node() {}
        Node(int first, int last) : first(first), last(last) {}
        friend ostream& operator<<(ostream& outs, const Node& node) {
            outs << "{first:" << node.first << " last:" << node.last << "}";
            return outs;
        }
    };
};