// 2019-02-10
#include <stdio.h>
#include <string.h>

const int MAX = 729 + 5;
const int fact[] = {0, 1, 3, 9, 27, 81, 243, 729};
char s[MAX][MAX];

void init(int siz) {
    for (int i = 1; i <= siz; ++i)
        memset(s[i] + 1, 0, sizeof(char) * siz);
}

void solve(int x, int y, int n) {
    if (n == 1) {
        s[x][y] = 'X';
        return;
    }
    int d = fact[n - 1];
    solve(x - d, y - d, n - 1), solve(x - d, y + d, n - 1);
    solve(x + d, y - d, n - 1), solve(x + d, y + d, n - 1);
    solve(x, y, n - 1);
}

void after(int siz) {
    for (int i = 1; i <= siz; ++i) {
        bool flag = false;
        s[i][siz + 1] = 0;
        for (int j = siz; j >= 1; --j) {
            if (s[i][j]) flag = true;
            if (flag && !s[i][j]) s[i][j] = ' ';
        }
    }
}

void print(int siz) {
    for (int i = 1; i <= siz; ++i)
        puts(s[i] + 1);
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF && ~n) {
        int x = (fact[n] + 1) >> 1;
        init(fact[n]);
        solve(x, x, n);
        after(fact[n]);
        print(fact[n]);
        puts("-");
    }
    return 0;
}
