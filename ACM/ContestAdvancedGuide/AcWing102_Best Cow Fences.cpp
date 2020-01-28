// 2019-02-01
#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 10;
const double EPS = 1e-5;

double a[MAXN], b[MAXN], sum[MAXN];

int main() {
    int n, f;
    scanf("%d%d", &n, &f);
    for (int i = 1; i <= n; ++i) {
        scanf("%lf", a + i);
    }
    double l = 0, r = 1e6;
    while(l + EPS < r) {
        double mid = (l + r) / 2.0; // average
        for (int i = 1; i <= n; ++i) {
            b[i] = a[i] - mid;
            sum[i] = sum[i - 1] + b[i];
        }
        double Min = 1e10, result = -1e10;
        for (int i = f; i <= n; ++i) {
            Min = min(Min, sum[i - f]);
            result = max(result, sum[i] - Min);
        }
        if (result > 0)
            l = mid;
        else
            r = mid;
    }
    printf("%d\n", (int)(1000 * r));
    return 0;
}
