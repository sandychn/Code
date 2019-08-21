/*
 * @Author: Sandy 
 * @Date: 2019-08-22 00:52:48 
 * @Last Modified by: Sandy
 * @Last Modified time: 2019-08-22 00:53:16
 */

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;

#ifdef _LOCAL
#define show(x) cerr << "[" << #x << ": " << x << "] (" << __LINE__ << ", in `" << __FUNCTION__ << "`)\n"
struct Tester {
    Tester() { freopen("sample.in", "r", stdin); }
    ~Tester() { fprintf(stderr, "\nTime: %d ms\n", int(1000.0 * clock() / CLOCKS_PER_SEC)); }
} _tester;
#else
#define show(x)
#endif

const int N = 2050;
const ULL SEED = 13331;

ULL base[N], ht[N];
int ans[N][N];
char s[N];

template <class value_type>
struct HashTable {
    static const int MAX = 5009;
    int first[MAX], tot;
    struct Node {
        ULL key;
        value_type value;
        int next;
    } node[MAX];
    void clear() {
        memset(first, -1, sizeof(first)), tot = 0;
    }
    int count(ULL key) const {
        ULL k = key % MAX;
        for (int i = first[k]; ~i; i = node[i].next) {
            if (node[i].key == key) return 1;
        }
        return 0;
    }
    // insert `value` into the hashtable
    // if the key is already exist,  returns <true, the old value>
    // if the key is not already exist, returns <false, the new value>
    pair<bool, value_type> insert(ULL key, value_type value) {
        ULL k = key % MAX;
        for (int i = first[k]; ~i; i = node[i].next) {
            if (node[i].key == key) {
                value_type old = node[i].value;
                node[i].value = value;
                return make_pair(true, old);
            }
        }
        node[tot].key = key, node[tot].value = value, node[tot].next = first[k];
        first[k] = tot++;
        return make_pair(false, value);
    }

    value_type &operator[](ULL key) {
        ULL k = key % MAX;
        for (int i = first[k]; ~i; i = node[i].next) {
            if (node[i].key == key) {
                return node[i].value;
            }
        }
        node[tot].key = key, node[tot].value = value_type(), node[tot].next = first[k];
        first[k] = tot++;
        return node[tot - 1].value;
    }
};

HashTable<int> mp;

ULL getHash(int l, int r) {
    return ht[r] - ht[l - 1] * base[r - l + 1];
}

int main() {
    base[0] = 1;
    for (int i = 1; i < N; ++i) base[i] = base[i - 1] * SEED;
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(ans, 0, sizeof(ans));
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        for (int i = 1; i <= len; ++i) ht[i] = ht[i - 1] * SEED + s[i];
        for (int l = 1; l <= len; ++l) {  // 子串长度
            mp.clear();
            for (int i = 1; i + l - 1 <= len; ++i) {  // 左端点
                ULL key = getHash(i, i + l - 1);      // 子串 [i, i + l - 1]
                ++ans[i][i + l - 1];
                pair<bool, int> ret = mp.insert(key, i);
                if (ret.first) {
                    int pos = ret.second;  // 子串 [pos, pos + l - 1] (pos < l) 与当前子串相同
                    --ans[pos][i + l - 1];
                    // 如串 ababab
                    // 在 l=2 时
                    // i = 1, ++mp[1][2]
                    // i = 3，++mp[3][4], --mp[1][4]
                    // i = 5, ++mp[5][6], --mp[3][6]
                }
            }
        }
        for (int i = len; i >= 1; --i) {  // 从大到小递推，则 mp[3][4] 会带给 mp[1][4], 重复的会被 mp[1][4] 中的 -1 抵消
            for (int j = i; j <= len; ++j) {
                ans[i][j] += ans[i + 1][j] + ans[i][j - 1] - ans[i + 1][j - 1];
            }
        }
        int q;
        scanf("%d", &q);
        while (q--) {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%d\n", ans[l][r]);
        }
    }
    return 0;
}