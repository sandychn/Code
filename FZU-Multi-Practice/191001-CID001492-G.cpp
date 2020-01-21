#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i < (int)(b); ++i)
#define per(i, a, b) for (int i = (b)-1; i >= (int)(a); --i)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define de(x) cout << #x << " = " << x << endl
#define dd(x) cout << #x << " = " << x << " "
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int N = 1e6 + 10;
const int M = 5;
const int INF = 0x3F3F3F3F;

int m, mod;

#define add(a, b) ((int)((a) + (b) >= mod ? (a) + (b)-mod : (a) + (b)))
#define mul(a, b) ((int)((LL)(a) * (b) % mod))

struct Matrix {
    int a[M][M];
    Matrix() { memset(a, 0, sizeof(a)); }
    Matrix operator*(const Matrix &b) const {
        Matrix res;
        rep(i, 0, m) {
            rep(j, 0, m) {
                rep(k, 0, m) {
                    res.a[i][j] = add(res.a[i][j], mul(a[i][k], b.a[k][j]));
                }
            }
        }
        return res;
    }
    void setOne() {
        memset(a, 0, sizeof(a));
        rep(i, 0, m) a[i][i] = 1;
    }
};

Matrix s[N], t[N], mat_a, mat_b;

int main() {
    int n;
    while (~scanf("%d%d%d", &n, &m, &mod)) {
        rep(i, 0, m) {
            rep(j, 0, m) { scanf("%d", &mat_a.a[i][j]); }
        }
        rep(i, 0, m) {
            rep(j, 0, m) { scanf("%d", &mat_b.a[i][j]); }
        }
        int top1 = 0, top2 = 0;
        Matrix tmp;  // mul all matrixs in stack s
        int t_top_index = 0;
        s[++top1] = tmp = mat_a;
        t[top2].setOne();
        rep(i, 1, n + 1) {
            int c;
            scanf("%d", &c);
            while (t_top_index < c) {
                if (top2 == 0) {
                    while (top1) {
                        ++top2;
                        t[top2] = s[top1--] * t[top2 - 1];
                    }
                    tmp.setOne();
                }
                --top2;
                ++t_top_index;
            }
            s[++top1] = t[top2] * tmp * mat_b;
            tmp = tmp * s[top1];
        }
        rep(i, 0, m) {
            rep(j, 0, m) {
                printf("%d", s[top1].a[i][j]);
                putchar(" \n"[j + 1 == m]);
            }
        }
    }
    return 0;
}