// 2019-04-18
#include <stdio.h>
#include <algorithm>

using namespace std;
typedef long long LL;
const int INF = 0x7FFFFFFF;

const int primes[11] = {-1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int c[11] = {30};
int ans = INF, ansDivisorCnt = 1;
int n;

// 当前位置 当前乘积 当前指数总和 约数个数
void dfs(int pos, LL product, int expSum, int divisorCnt) {
    if (pos == 11) {
        if (divisorCnt > ansDivisorCnt || (divisorCnt == ansDivisorCnt && ans > product))
            ans = product, ansDivisorCnt = divisorCnt;
        return;
    }

    LL p = 1; // this number.
    for (c[pos] = 0; c[pos - 1] >= c[pos]; ++c[pos], p *= primes[pos]) {
        if (expSum + c[pos] > 30 || product * p > n) break;
        dfs(pos + 1, product * p, expSum + c[pos], divisorCnt * (c[pos] + 1));
    }
}

int main() {
    scanf("%d", &n);
    dfs(1, 1, 0, 1);
    printf("%d\n", ans);
    return 0;
}