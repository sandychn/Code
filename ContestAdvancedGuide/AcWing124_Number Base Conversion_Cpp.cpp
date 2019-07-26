// 2019-02-10
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int MAX = 1005;

char s[MAX], t[MAX];
int a[MAX];

inline int charToInt(char x) {
    int xx = x;
    if (x <= '9') return xx - '0';
    if (x <= 'Z') return xx - 'A' + 10;
    return xx - 'a' + 36;
}

inline char intToChar(int x) {
    if (x < 10) return x + '0';
    if (x < 36) return x - 10 + 'A';
    return x - 36 + 'a';
}

void change(int in, int out, char *const s, char *t, int *temp) {
    int len = strlen(s), k = 0;
    for (int i = 0; s[i]; ++i) temp[i] = charToInt(s[len - 1 - i]);
    // temp[0]低位 temp[len - 1]高位
    --len;
    while (len >= 0) {
        // 高位往低位进
        for (int i = len; i >= 1; --i) {
            temp[i - 1] += temp[i] % out * in;
            temp[i] /= out;
            if (len >= 0 && i == len && !temp[i]) --len;
        }
        t[k++] = intToChar(temp[0] % out);
        temp[0] /= out;
        if (!temp[0] && !len) --len;
    }
    t[k] = 0; // 字符串结束
    for (int i = 0; i < k >> 1; ++i)
        swap(t[i], t[k - i - 1]); // 反转
}

int main() {
    int n; scanf("%d", &n);
    while (n--) {
        int in, out; scanf("%d%d%s", &in, &out, s);
        change(in, out, s, t, a);
        printf("%d %s\n%d %s\n\n", in, s, out, t);
    }
    return 0;
}
