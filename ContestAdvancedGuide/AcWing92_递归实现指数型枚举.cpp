// 2019-01-31
#include <stdio.h>

int a[20], st[20], n;

void rec(int pos, int cnt, int sign) {
    if (sign) {
        for (int i = 0; i < cnt; ++i) {
            printf("%d%c", st[i], " \n"[i == cnt - 1]);
        }
    }
    if (pos == n) return;
    st[cnt] = a[pos];
    rec(pos + 1, cnt + 1, 1);
    rec(pos + 1, cnt, 0);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }
    puts("");
    rec(0, 0, 0);
    return 0;
}
