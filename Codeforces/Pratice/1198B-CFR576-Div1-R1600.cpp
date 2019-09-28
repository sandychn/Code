#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5 + 50;

int a[N];
int lastUpd[N];
pair<int, int> stk[N]; // first: value, second: time
int top;

int lowerBound(int val) {
    int l = 0, r = top;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (stk[mid].second < val) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int q;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y;
            cin >> x >> y;
            lastUpd[x] = i;
            a[x] = y;
        } else {
            int y;
            cin >> y;
            while (top && stk[top - 1].first <= y) --top;
            stk[top++] = make_pair(y, i);
        }
    }
    stk[top++] = make_pair(-1, q + 1);
    for (int i = 1; i <= n; ++i) {
        int pos = lowerBound(lastUpd[i]);
        a[i] = max(a[i], stk[pos].first);
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}