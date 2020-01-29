#include <bits/stdc++.h>
using namespace std;

const int N = 10050;

int a[N], b[N];

int count(int n, int m, int ans) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int val = a[i];
        int left = 0, right = m + 1;
        while (left + 1 < right) {
            int mid = (left + right) >> 1;
            if (val * b[mid] <= ans) {
                left = mid;
            } else {
                right = mid;
            }
        }
        cnt += left;
    }
    return cnt;

}

int main() {
    int n, m, k;
    while (~scanf("%d%d%d", &n, &m, &k)) {
        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        for (int i = 1; i <= m; i++) scanf("%d", b + i);
        sort(a + 1, a + n + 1);
        sort(b + 1, b + m + 1);
        int left = a[1] * b[1] - 1;
        int right = a[n] * b[m] + 1;
        while (left + 1 < right) {
            int mid = (left + right) >> 1;
            int cnt = count(n, m, mid);
            if (cnt < k) {
                left = mid;
            } else {
                right = mid;
            }
        }
        printf("%d\n", right);
    }
    return 0;
}