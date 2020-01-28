#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int minDeletionSize(vector<string>& A) {
        if (A.empty()) {
            return 0;
        }
        int len = A[0].size();
        bool* isDeleted = new bool[len];
        memset(isDeleted, false, sizeof(bool) * len);
        queue<Node> q;
        q.emplace(0, A.size() - 1, 0);
        while (!q.empty()) {
            int cnt = q.size();
            while (cnt--) {
                const Node fnt = q.front();
                q.pop();
                cout << fnt << endl;
                char pre = 0;
                Node changed(fnt.first, fnt.first, fnt.charIndex + 1);
                bool flag = false;
                for (int i = fnt.first; i <= fnt.last; i++) {
                    char ch = A[i][fnt.charIndex];
                    if (pre < ch) {
                    } else if (pre == ch) {
                        changed.last = i;
                    } else {  // pre > ch
                        isDeleted[fnt.charIndex] = true;
                        changed = Node(fnt.first, fnt.last, fnt.charIndex + 1);
                        if (changed.first != changed.last && changed.charIndex < len) {
                            q.push(changed);
                        }
                        flag = true;
                        break;
                    }
                    pre = ch;
                }
                if (!flag && changed.first != changed.last && changed.charIndex < len) {
                    q.push(changed);
                }
            }
        }
        // cout.setf(ios::boolalpha);
        // for (int i = 0; i < len; i++) {
        //     cout << isDeleted[i] << ' ';
        // }
        // cout << endl;
        int deleted = accumulate(isDeleted, isDeleted + len, 0);
        delete[] isDeleted;
        return deleted;
    }

   private:
    struct Node {
        int first, last, charIndex;
        Node() {}
        Node(int first, int last, int charIndex) : first(first), last(last), charIndex(charIndex) {}
        friend ostream& operator<<(ostream& outs, const Node& node) {
            outs << "{first:" << node.first << " last:" << node.last
                 << " charIndex:" << node.charIndex << "}";
            return outs;
        }
    };
};

int main() {
    vector<string> A = {"doeeqiy", "yabhbqe", "twckqte"};
    int result = Solution().minDeletionSize(A);
    cout << "Return " << result << endl;
}

/*
dbc
bbc
bcd
aab
aac

1, 2, 3, 4, 5
1; 2, 3; 4, 5

*/