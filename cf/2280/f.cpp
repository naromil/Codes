#include <bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll = long long;
const int kn = 6e5 + 65;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int n, m;
vector<pair<int, int>> c[kn];
int sd, su, td, tu;

class Dijk {
public:
    int x;
    ll dis;
    bool operator < (const Dijk &v) const {
        return dis > v.dis;
    }
};

ll dis[kn];
bool vis[kn];

inline void dijkstra(int o) {
    for (int i = 0; i <= n * 3; i++) {
        dis[i] = inf;
        vis[i] = false;
    }
    priority_queue<Dijk> pq;
    pq.push({o, 0});
    dis[o] = 0;

    while (!pq.empty()) {
        int u = pq.top().x; pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto vr : c[u]) {
            int v = vr.first, w = vr.second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.push({v, dis[v]});
            }
        }
    }
}

inline void addedge(int x, int y, int w) {
    c[x].emp(make_pair(y, w));
    c[y].emp(make_pair(x, w));
    // printf("%d %d\n", x, y);
}
inline void _solv() {
    cin >> n >> m >> sd >> su >> td >> tu;
    for (int i = 0; i <= n * 3; i++) {
        c[i].clear();
    }

    for (int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        addedge(x, y, 1);
        addedge(x + n, y + n, 3);
        addedge(x + n * 2, y + n * 2, 1);
    }

    for (auto cr : c[sd]) {
        int u = cr.first;
        if (u != td) addedge(u, u + n, 2);
        else addedge(u, sd + n * 2, 1);
    }
    for (auto cr : c[td]) {
        int u = cr.first;
        if (u > n) continue;
        addedge(u + n, u + n * 2, 2);
    }

    dijkstra(su);
    if (sd == td) printf("%lld\n", dis[tu]);
    else printf("%lld\n", dis[tu + n * 2]);
}
signed main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) _solv();
}
