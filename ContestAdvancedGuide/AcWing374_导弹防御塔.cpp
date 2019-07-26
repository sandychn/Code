/*
 * @Author: Sandy
 * @Date: 2019-07-17 15:32:25
 * @Last Modified by: Sandy
 * @Last Modified time: 2019-07-17 16:46:36
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 55;

struct Point {
    int x, y;
    Point() {}
    Point(int _x, int _y): x(_x), y(_y) {}
};

struct Edge {
    int to;
    double w;
    Edge() {}
    Edge(int _to, double _w): to(_to), w(_w) {}
};

int link[N];
double time[N]; // every turret time spent
vector<int> attack[N]; // attack[i] contains turret %i attacks
vector<Edge> gAll[N], g[N];
bool vis[N];

double dist(const Point &a, const Point &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int match(int turretId, double mid) {
    for (size_t i = 0; i < g[turretId].size(); ++i) {
        int to = g[turretId][i].to;
        double w = g[turretId][i].w;
        if (link[to]) continue;
        if (time[i] + w <= mid) {
                                       
        }
    }
}

// determine if the answer is mid, all the invaders are hit or not
bool check(int n, int m, double mid) {
    memset(time, 0, sizeof(time));
    memset(link, 0, sizeof(link));
    for (int i = 1; i <= n; ++i) {
        g[i].clear();
        for (size_t j = 0; j < gAll[i].size(); ++j) {
            if (gAll[i][j].w <= mid) g[i].push_back(gAll[i][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += match(i);
    }
    return ans == m;
}

int main() {
    int n, m, t1, t2, v;
    Point invader[N], turret[N];
    cin >> n >> m >> t1 >> t2 >> v;
    for (int i = 1; i <= m; ++i) cin >> invader[i].x >> invader[i].y;
    for (int i = 1; i <= n; ++i) cin >> turret[i].x >> turret[i].y;
    // construct the graphz
    for (int i = 1; i <= n; ++i) { // turret
        for (int j = 1; j <= m; ++j) { // invader
            double d = dist(turret[i], invader[j]);
            double timeCost = d / v + t1 + t2;
            gAll[i].emplace_back(j, timeCost);
        }
    }
    double l = 0, r = 1e6;
    int tt = 100;
    while (tt--) {
        double mid = (l + r) / 2;
        if (check(n, m, mid)) r = mid;
        else l = mid;
    }
    printf("%.6f\n", r);
    return 0;
}