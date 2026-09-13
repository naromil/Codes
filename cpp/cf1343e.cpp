#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e5 + 25;
int n, m, cst[kn];
vector<int> c[kn];
ll sum[kn];
class DijkstraNetwork{
    public: int o, dis[kn], vis[kn];
    inline void dijkstra(){
        for(int i=0; i<=n+5; ++i){ vis[i] = 0; dis[i] = 0x3f3f3f3f; }
        queue<int> q;
        dis[o] = 0;
        q.push(o);
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(vis[u]) continue;
            vis[u] = 1;
            for(auto v: c[u]){
                if(dis[v] > dis[u] + 1){
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }
    }
}g[3];
inline void _solv(){
    cin >> n >> m >> g[0].o >> g[1].o >> g[2].o;
    for(int i=0; i<=max(n,m)+5; ++i){
        cst[i] = sum[i] = 0;
        c[i].clear();
    }
    for(int i=1; i<=m; ++i) cin >> cst[i];
    sort(cst + 1, cst + m + 1);
    for(int i=1; i<=m; ++i){
        sum[i] = sum[i-1] + cst[i];
    }

    for(int i=1; i<=m; ++i){
        int x, y; cin >> x >> y;
        c[x].emp(y);
        c[y].emp(x);
    }
    g[0].dijkstra();
    g[1].dijkstra();
    g[2].dijkstra();

    ll ans = 0x3f3f3f3f3f3f3f3f;
    for(int i=1; i<=n; ++i){
        int diss = g[0].dis[i] + g[1].dis[i] + g[2].dis[i];
        if(diss > m) continue;
        ans = min(ans, sum[diss] + sum[g[1].dis[i]]);
    }
    printf("%lld\n", ans);
}
signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    int T; cin >> T; while(T--) _solv();
    return 0;
}