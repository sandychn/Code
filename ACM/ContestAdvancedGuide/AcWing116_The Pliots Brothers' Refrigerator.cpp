// 2019-02-10
#include <stdio.h>
#include <string.h>

char mp[4][5];
char now[4][5];

void change(int i, int j) {
    for (int y = 0; y < 4; ++y)
        now[i][y] = now[i][y] == '-' ? '+' : '-';
    for (int x = 0; x < 4; ++x)
        now[x][j] = now[x][j] == '-' ? '+' : '-';
    now[i][j] = now[i][j] == '-' ? '+' : '-';
}

int main() {
    for (int i = 0; i < 4; ++i)
        scanf("%s", mp[i]);
    for (int p = 0; p + 1 < 1 << 17; ++p) {
        memcpy(now, mp, sizeof(mp));
        int ans = 0;
        for (int cnt = 0, x = 0, y = 0; cnt < 16; ++cnt) {
            if ((p >> cnt) & 1)
                change(x, y), ++ans;
            if (++y > 3) ++x, y = 0;
        }
        bool flag = true;
        for (int i = 0; i < 4 && flag; ++i)
            for (int j = 0; j < 4 && flag; ++j)
                flag = (now[i][j] == '-');
        if (flag) {
            printf("%d\n", ans);
            for (int cnt = 0, x = 0, y = 0; cnt < 16; ++cnt) {
                if ((p >> cnt) & 1)
                    printf("%d %d\n", x + 1, y + 1);
                if (++y > 3) ++x, y = 0;
            }
            break;
        }
    }
    return 0;
}
