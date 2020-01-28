#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;

#ifdef _LOCAL
#define show(x) cerr << "[" << #x << ": " << x << "] (" << __LINE__ << ", in `" << __FUNCTION__ << "`)\n"
struct Tester {
    Tester() { freopen("sample.in", "r", stdin); }
    ~Tester() { fprintf(stderr, "\nTime: %d ms\n", int(1000.0 * clock() / CLOCKS_PER_SEC)); }
} _tester;
#else
#define show(x)
#endif

namespace Fast_IO {
static const unsigned int BUFSIZE = 3 << 20;
static char inbuf[BUFSIZE], *p1 = inbuf, *p2 = inbuf;
inline int nc() {
    return p1 != p2 ? *p1++ : ((p1 = inbuf) == (p2 = inbuf + fread(inbuf, sizeof(char), BUFSIZE, stdin)) ? -1 : *p1++);
}
template <class T>
inline bool read(T &x) {
    register int ch, flag = 1;
    while ((ch = nc()) < '0' || ch > '9') {
        if (ch == -1) return false;
        ch == '-' && (flag = -1);
    }
    x = ch - '0';
    while ((ch = nc()) >= '0' && ch <= '9') x = x * 10 + (ch - '0');
    return x *= flag, true;
}
template <class T>
inline void print(T x) {
    static char t[30];
    if (x == 0) {
        putchar('0');
    } else {
        if (x < 0) putchar('-'), x = -x;
        register int tp = 0;
        while (x) t[++tp] = x % 10 + '0', x /= 10;
        while (tp) putchar(t[tp--]);
    }
}
}  // namespace Fast_IO
using Fast_IO::print;
using Fast_IO::read;

const int N = 1e5 + 10;
const int M = 1e5 + 10;

struct Query {
    int x, y, id;
    bool operator<(const Query &b) const { return x < b.x; }
} q[M];

struct Point {
    int first, second;
} a[N];

int ans[M], tree[N + M];
int compressX[N + M], cntX;
int compressY[N + M], cntY;
vector<int> point[N + M];  // b[i] contains point's id(y) which id(x)=i

inline int lowbit(int x) {
    return x & -x;
}

int ask(int pos) {
    int sum = 0;
    while (pos) sum += tree[pos], pos -= lowbit(pos);
    return sum;
}

void add(int val, int pos, int n) {
    while (pos <= n) {
        tree[pos] += val;
        pos += lowbit(pos);
    }
}

int getId_x(int val) {
    return lower_bound(compressX, compressX + cntX, val) - compressX + 1;
}

int getId_y(int val) {
    return lower_bound(compressY, compressY + cntY, val) - compressY + 1;
}

int main() {
    int n, m;
    read(n), read(m);
    for (int i = 1; i <= n; ++i) {
        read(a[i].first), read(a[i].second);
        compressX[cntX++] = a[i].first;
        compressY[cntY++] = a[i].second;
    }
    for (int i = 1; i <= m; ++i) {
        read(q[i].x), read(q[i].y);
        q[i].id = i;
        compressX[cntX++] = q[i].x;
        compressY[cntY++] = q[i].y;
    }
    sort(compressX, compressX + cntX);
    sort(compressY, compressY + cntY);
    cntX = unique(compressX, compressX + cntX) - compressX;
    cntY = unique(compressY, compressY + cntY) - compressY;
    for (int i = 1; i <= n; ++i)
        point[getId_x(a[i].first)].push_back(getId_y(a[i].second));
    sort(q + 1, q + m + 1);
    int currentXId = 0;
    for (int i = 1; i <= m; ++i) {
        int xId = getId_x(q[i].x), yId = getId_y(q[i].y);
        while (currentXId < xId) {
            ++currentXId;
            for (int j = 0; j < (int)point[currentXId].size(); ++j)
                add(1, point[currentXId][j], cntY);
        }
        ans[q[i].id] = ask(yId);
    }
    for (int i = 1; i <= m; ++i) print(ans[i]), putchar('\n');
    return 0;
}