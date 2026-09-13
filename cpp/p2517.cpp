#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 555, inf = 0x3f3f3f3f;
int n, m, W, S, T, a[kn], b[kn];
ll dis[kn];
bool vis[kn];
int flw[kn], pre[kn];
ll ans = 0;

class Edge{ public: int y, w, c, r; }e[kn<<2];
int hd[kn], ct = 1;
inline void addedge(int x, int y, int w, int c){
    e[++ct].y = y;
    e[ct].w = w;
    e[ct].c = c;
    e[ct].r = hd[x];
    hd[x] = ct;
    e[++ct].y = x;
    e[ct].w = 0;
    e[ct].c = -c;
    e[ct].r = hd[y];
    hd[y] = ct;
}

inline bool spfa(){
    memset(dis, 0x3f, sizeof dis);
    queue<int> q;
    q.push(S);
    flw[S] = inf;
    dis[S] = 0;
    vis[S] = true;
    while(!q.empty()){
        int u = q.front(); q.pop();
        vis[u] = false;
        for(int j=hd[u]; j; j=e[j].r){
            int v = e[j].y;
            if(!e[j].w || dis[v] <= dis[u] + e[j].c) continue;
            dis[v] = dis[u] + e[j].c;
            flw[v] = min(flw[u], e[j].w);
            pre[v] = j;
            if(!vis[v]) q.push(v);
            vis[v] = true;
        }
    }
    return dis[T] < 0x3f3f3f3f3f3f3f3f;
}
inline void upd(){
    int u = T;
    while(u != S){
        e[pre[u]].w -= flw[T];
        e[pre[u]^1].w += flw[T];
        u = e[pre[u]^1].y;
    }
    ans += 1ll * flw[T] * dis[T];
}

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> W >> m;
    S = n + 1;
    T = S + 1;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        addedge(i, T, a[i], 0);
    }
    for(int i=1; i<=n; ++i){
        cin >> b[i];
        addedge(S, i, inf, b[i]);
    }
    for(int i=1; i<n; ++i){
        addedge(i, i+1, m, W);
    }
    while(spfa()) upd();
    printf("%lld\n", ans);
    return 0;
}