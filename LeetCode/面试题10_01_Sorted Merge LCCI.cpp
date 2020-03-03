// Time  : 4 ms
// Memory: 11.5 MB

class Solution {
public:
    void _merge(vector<int>& A, int m, vector<int>& B, int n) {
        int x = m - 1, y = n - 1;
        for (int i = m + n - 1; i >= 0; i--) {
            if (y >= 0 && (x < 0 || A[x] < B[y])) {
                A[i] = B[y--];
            } else {
                A[i] = A[x--];
            }
        }
    }

    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        _merge(A, m, B, n);
        return;

        // Solution at first
        int x = 0, y = 0;
        queue<int> q;
        for (int i = 0; i < m + n; i++) {
            vector<pair<int, int>> v;
            if (x < m) v.emplace_back(A[x], 0);
            if (y < n) v.emplace_back(B[y], 1);
            if (!q.empty()) v.emplace_back(q.front(), 2);
            
            pair<int, int> minimum = {0, -1};
            for (const pair<int, int>& p : v) {
                if (minimum.second == -1 || p.first < minimum.first) {
                    minimum = p;
                }
            }
            
            switch (minimum.second) {
                case 0:
                    ++x;
                    break;
                case 1:
                    if (x < m) q.push(A[x]);
                    A[x++] = B[y++];
                    break;
                case 2:
                    if (x < m) q.push(A[x]);
                    A[x++] = q.front();
                    q.pop();
                    break;
            }
        }
    }
};
