// 2019-04-13
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int N = 1005;
int dist[N], visitCount[N];
vector<pair<int, int> > edge[N];
vector<pair<int, int> > reversedEdge[N];

struct Node1 {
    int pos, cost;
    Node1(int Pos, int Cost) : pos(Pos), cost(Cost) {}
    bool operator<(const Node1 &b) const { return cost > b.cost; }
};

struct Node2 {
    int pos, cost;
    Node2(int Pos, int Cost) : pos(Pos), cost(Cost) {}
    bool operator<(const Node2 &b) const { return cost + dist[pos] > b.cost + dist[b.pos]; }
};

void dijkstra(int start) {
    memset(dist, 0x3F, sizeof(dist));
    priority_queue<Node1> q;
    q.push(Node1(start, 0));
    while (!q.empty()) {
        Node1 now = q.top();
        q.pop();
        if (now.cost > dist[now.pos]) continue;
        dist[now.pos] = now.cost;
        for (size_t i = 0; i < reversedEdge[now.pos].size(); ++i) {
            int to = reversedEdge[now.pos][i].first;
            int w = reversedEdge[now.pos][i].second;
            if (now.cost + w < dist[to]) {
                dist[to] = now.cost + w;
                q.push(Node1(to, now.cost + w));
            }
        }
    }
}

int kthShortestPath(int start, int end, int k) {
    if (start == end) ++k;
    priority_queue<Node2> q;
    q.push(Node2(start, 0));
    while (!q.empty()) {
        Node2 now = q.top();
        q.pop();
        ++visitCount[now.pos];
        if (now.pos == end && visitCount[now.pos] == k) {
            return now.cost;
        }
        for (size_t i = 0; i < edge[now.pos].size(); ++i) {
            int to = edge[now.pos][i].first, w = edge[now.pos][i].second;
            if (visitCount[to] < k) q.push(Node2(to, now.cost + w));
        }
    }
    return -1;
}

int main() {
    int n, m, u, v, w, start, end, k;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        edge[u].push_back(make_pair(v, w));
        reversedEdge[v].push_back(make_pair(u, w));
    }
    scanf("%d%d%d", &start, &end, &k);
    dijkstra(end);
    printf("%d\n", kthShortestPath(start, end, k));
    return 0;
}