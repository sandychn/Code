/*
 * @Author: Sandy 
 * @Date: 2019-08-22 00:53:36 
 * @Last Modified by:   Sandy 
 * @Last Modified time: 2019-08-22 00:53:36 
 */

namespace IO {
static const unsigned int BUFSIZE = 16 << 20;  // 16M缓冲区
static char inbuf[BUFSIZE], *p1 = inbuf, *p2 = inbuf;
#define gc (p1 != p2 ? *p1++ : ((p1 = inbuf) == (p2 = inbuf + fread(inbuf, sizeof(char), BUFSIZE, stdin)) ? -1 : *p1++))
template <class T>
inline bool read(T &x) {
    register int ch, flag = 1;
    while ((ch = gc) < '0' || ch > '9') {
        if (ch == -1) return false;
        ch == '-' && (flag = -1);
    }
    x = ch - '0';
    while ((ch = gc) >= '0' && ch <= '9') x = x * 10 + (ch - '0');
    return x *= flag, true;
}
template <class T>
inline void print(T x) {
    static char t[50];  // int128 needs 50
    (x < 0 && (putchar('-'), x = -x)) || (!x && putchar('0'));
    register int tp = 0;
    while (x) t[++tp] = x % 10 + '0', x /= 10;
    while (tp) putchar(t[tp--]);
}
#undef gc
}  // namespace IO

using IO::print;
using IO::read;