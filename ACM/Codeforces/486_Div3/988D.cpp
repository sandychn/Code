#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#if __cplusplus >= 201103L
#include <chrono>
#include <complex>
#include <random>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;

const int N = 2e5 + 10;
const int MAX = 1e9;

map<LL, int> mp;
vector<LL> res;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        mp.emplace(a[i], i);
    }
    for (int i = 1; i <= n; ++i) {
        if (res.empty()) res.push_back(a[i]);
        for (int j = 0; ; ++j) {
            LL diff = 1LL << j;
            if (a[i] + diff > MAX) break;
            if (mp.count(a[i] + diff)) {
                if (a[i] + diff + diff <= MAX && mp.count(a[i] + diff + diff)) {
                    res = {a[i], a[i] + diff, a[i] + diff + diff};
                    break;
                } else {
                    if (int(res.size()) < 2) res = {a[i], a[i] + diff};
                }
            }
        }
    }
    cout << res.size() << endl;
    for (int pos : res) cout << pos << ' ';
    return 0;
}