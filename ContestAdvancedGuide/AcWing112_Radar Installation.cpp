// 2019-02-08
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;

pair<int, int> island[1005];

double dx(double d, double y) {
    return sqrt(d * d - y * y);
}

int main() {
    int n, d; cin >> n >> d;
    for (int i = 0; i < n; ++i) {
        cin >> island[i].first >> island[i].second;
        if (island[i].second > d) {
            cout << -1;
            return 0;
        }
    }
    sort(island, island + n);
    int ans = 0;
    double r = -1e30;
    for (int i = 0; i < n; ++i) {
        double dist = dx(d, island[i].second);
        if (r < island[i].first - dist) {
            ++ans;
            r = island[i].first + dist;
        } else {
            r = min(r, island[i].first + dist);
        }
    }
    cout << ans;
    return 0;
}
