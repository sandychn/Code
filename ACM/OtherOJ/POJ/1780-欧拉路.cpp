// 最终答案的长度是 10^n + n - 1 的解释
// 第一个全0串的长度是10^n，此后每个串都可以与前一个串共享除第一个字符外的所有字符
// 10^n总共有n个串，所以共享后最终结果是10^n+n-1的长度

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <stack>

using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
const int INF = 0x3F3F3F3F;
const LL INFLL = 0x3F3F3F3F3F3F3F3FLL;

#ifdef _LOCAL
#define show(x)                                                     \
    cerr << "[" << #x << ": " << x << "] (" << __LINE__ << ", in `" \
         << __FUNCTION__ << "`)\n"
struct Tester {
    Tester() { freopen("sample.in", "r", stdin); }
    ~Tester() {
        cerr << "\nTime: " << int(1000.0 * clock() / CLOCKS_PER_SEC) << " ms\n";
    }
} _tester;
#else
#define show(x)
#endif

const int N = 1e6 + 10;

int powers[10], cnt[N], n;
stack<int> stk;
stack<char> ans;

void search(int u) {
    while (cnt[u] < 10) {
        int w = 10 * u + cnt[u];
        stk.push(w);
        ++cnt[u];
        u = w % powers[n - 1];
    }
}

int main() {
    powers[0] = 1;
    for (int i = 1; i < 8; ++i) powers[i] = powers[i - 1] * 10;
    while (~scanf("%d", &n) && n) {
        for (int i = 0; i < powers[n - 1]; ++i) cnt[i] = 0;
        search(0);
        while (!stk.empty()) {
            int w = stk.top();
            stk.pop();
            ans.push(w % 10 + '0');
            search(w / 10);
        }
        if (n - 1 > 0) printf("%0*d", n - 1, 0);  // 输出n-1个0
        while (!ans.empty()) {
            putchar(ans.top());
            ans.pop();
        }
        puts("");
    }
    return 0;
}
