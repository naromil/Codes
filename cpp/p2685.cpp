#include<bits/stdc++.h>
#define pii pair<int,int>
#define x first
#define y second
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e5 + 25;
int n, m;
class Edge{ public: int y; ll w; int r; }e[kn<<1];
int hd[kn], ct = 1;
inline void addedge(int x, int y, int w){
    e[++ct].y = y;
    e[ct].w = w;
    e[ct].r = hd[x];
    hd[x] = ct;
}

ll dis[2][kn];
int vis[kn], pre[2][kn];
inline void dijkstra(int o, int op){
    memset(dis[op], 0x3f, sizeof dis[op]);
    memset(vis, 0, sizeof vis);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dis[op][o] = 0;
    pq.push({0, o});
    while(!pq.empty()){
        int u = pq.top().y; pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(int j=hd[u]; j; j=e[j].r){
            int v = e[j].y; ll w = e[j].w;
            if(dis[op][v] > dis[op][u] + w){
                dis[op][v] = dis[op][u] + w;
                pre[op][v] = u;
                pq.push({dis[op][v], v});
            }
        }
    }
}

int b[kn];
inline void findway(int u){
    if(u == 1) return;
    b[pre[0][u]] = b[u] - 1;
    findway(pre[0][u]);
}

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1; i<=m; ++i){
        int x, y; ll w; cin >> x >> y >> w;
        addedge(x, y, w);
        addedge(y, x, w);
    }
    dijkstra(1, 0);
    dijkstra(n, 1);
    b[n] = dis[0][n] + 1;
    findway(n);
    return 0;
}