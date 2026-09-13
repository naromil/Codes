#include<bits/stdc++.h>
#define emp emplace_babck
using namespace std;
using ll=long long;
const int kn = 648, inf = 0x3f3f3f3f;
int n, m, S, T, W[64][16];
struct Edge{ int y, w, c, r; }e[327680];
int hd[kn], ct=1;
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
int flow[kn], dis[kn], pre[kn];
bool vis[kn];
inline bool spfa(){
    memset(dis, 0x3f, sizeof dis);
    queue<int> q;
    q.push(S);
    flow[S] = inf;
    dis[S] = 0;
    vis[S] = true;
    while(!q.empty()){
        int u = q.front(); q.pop();
        vis[u] = false;
        for(int j=hd[u]; j; j=e[j].r){
            int v = e[j].y, flw = e[j].w, w = e[j].c;
            if(flw && dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                flow[v] = min(flow[u], flw);
                pre[v] = j;
                if(!vis[v]){ q.push(v); vis[v] = true; } // why typed vis[u] = true?
            }
        }
    }
    return dis[T] < inf;
}
int maxcost = 0;
inline void update(int flw){
    int u = T;
    while(u != S){ // not "T != S"
        e[pre[u]].w -= flw;
        e[pre[u]^1].w += flw;
        u = e[pre[u]^1].y;
    }
    maxcost += flw * dis[T];
}
signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> m >> n;
    S = n * m + n + 1;
    T = S + 1;
    for(int i=1; i<=n; ++i){
        addedge(S, i, 1, 0);
        for(int j=1; j<=m; ++j){
            addedge(n*j+i, T, 1, 0);
            cin >> W[i][j];
            for(int k=1; k<=n; ++k)
                addedge(i, n*j+k, 1, k*W[i][j]);
        }
    }
    while(spfa()) update(flow[T]);
    printf("%.2f\n", 1.0 * maxcost / n);
    return 0;
}