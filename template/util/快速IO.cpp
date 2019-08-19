namespace Fast_IO {
static const unsigned int BUFSIZE = 3 << 20;  // 3M缓冲区
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