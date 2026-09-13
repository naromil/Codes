#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 6e3 + 63, km = 9e4 + 94, inf = 0x3f3f3f3f;
int n, m, q, S, T;
class Edge{ public: int y, w, r; }e[km];
int hd[kn], ct = 1;
inline void addedge(int x, int y, int w){
    e[++ct].y = y;
    e[ct].w = w;
    e[ct].r = hd[x];
    hd[x] = ct;
    e[++ct].y = x;
    e[ct].w = 0;
    e[ct].r = hd[y];
    hd[y] = ct;
}

int lv[kn], crt[kn];
inline bool bfs(){
    memset(lv, 0, sizeof lv);
//    for(int i=1; i<=T; ++i) crt[i] = hd[i];
    queue<int> q;
    q.push(S);
    crt[S] = hd[S];
    lv[S] = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int j=hd[u]; j; j=e[j].r){
            int v = e[j].y, w = e[j].w;
            if(!w || lv[v]) continue;
            lv[v] = lv[u] + 1;
            crt[v] = hd[v];
            q.push(v);
            if(v == T) return true;
        }
    }
    return false;
}
inline int dinic(int u, int flw){
    if(u == T) return flw;
    int rem = flw;
    for(int j=crt[u]; j&&rem; j=e[j].r){
        int v = e[j].y, w = e[j].w;
        if(!w || lv[v] != lv[u] + 1) continue;
        int res = dinic(v, min(rem, w)); // flw -> rem
        if(!res) lv[v] = 0;
        rem -= res;
        e[j].w -= res;
        e[j^1].w += res;
        crt[u] = j;
    }
    return flw - rem;
}

bool cow[kn]; ///
signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    S = 1;
    T = (n<<1) + 1;
    for(int i=1; i<=m; ++i){
        int x, y; cin >> x >> y;
        addedge(x + n, y, inf);
        addedge(y + n, x, inf);
    }
    addedge(1, 1 + n, inf);
    cow[1] = true;
    for(int i=1; i<=q; ++i){
        int x; cin >> x;
        cow[x] = true;
        addedge(x, x + n, inf);
        addedge(x + n, T, inf);
    }
    for(int i=1; i<=n; ++i){
        if(!cow[i]) addedge(i, i + n, 1);
    }
    
    int mxflw = 0;
    while(bfs()) mxflw += dinic(S, inf);
    printf("%d\n", mxflw);
    return 0;
}