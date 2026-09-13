#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 16384, inf = 0x3f3f3f3f;
int n, m, S, T;
struct Edge{ int y, w, r; }e[327680];
int hd[kn], ct=1;
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
int col[kn];
vector<int> c[kn];
inline void init(int u){
    for(auto v: c[u]){
        if(col[v] == -1){
            col[v] = col[u] ^ 1;
            init(v);
        }
    }
}
int lv[kn], crt[kn];
inline bool bfs(){
    memset(lv, 0, sizeof lv);
    queue<int> q;
    q.push(S);
    lv[S] = 1;
    crt[S] = hd[S];
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int j=hd[u]; j; j=e[j].r){
            int v = e[j].y, w = e[j].w;
            if(!w || lv[v]) continue;
            crt[v] = hd[v];
            lv[v] = lv[u] + 1;
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
        if(!w || lv[v]!=lv[u]+1) continue;
        int res = dinic(v, min(rem, w));
        if(!res) lv[v] = 0;
        rem -= res;
        e[j].w -= res;
        e[j^1].w += res;
        crt[u] = j;
    }
    return flw - rem;
}
int dfn[kn], low[kn], dft=0, scc[kn], sct=0, ins[kn];
stack<int> stk;
inline void tarjan(int u){
    dfn[u] = low[u] = ++dft;
    ins[u] = true;
    stk.push(u);
    for(int j=hd[u]; j; j=e[j].r){
        if(!e[j].w) continue;
        int v = e[j].y;
        if(!dfn[v]){ tarjan(v); low[u] = min(low[u], low[v]); }
        else if(ins[v]) low[u] = min(low[u], dfn[v]);
    }
    if(dfn[u] == low[u]){
        ++sct;
        while(!stk.empty()){
            int v = stk.top(); stk.pop();
            ins[v] = false;
            scc[v] = u;
            if(v == u) break;
        }
    }
}
signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> m;
    S = n + 1;
    T = n + 2;
    for(int i=1; i<=m; ++i){
        int x, y; cin >> x >> y;
        c[x].emp(y);
        c[y].emp(x);
    }

    memset(col, -1, sizeof col);
    for(int i=1; i<=n; ++i){
        if(col[i] == -1){ col[i] = 0; init(i); }
        if(col[i] == 1){ addedge(i, T, 1); }
        else{
            addedge(S, i, 1);
            for(auto v: c[i]) addedge(i, v, 1);
        }
    }
    int maxflow = 0;
    while(bfs()) maxflow += dinic(S, inf);

    for(int i=1; i<=T; ++i)
        if(!dfn[i]) tarjan(i);

    vector<pair<int,int>> ans;
    for(int u=1; u<=n; ++u){
        if(col[u] != 0) continue;
        for(int j=hd[u]; j; j=e[j].r){
            int v = e[j].y, w = e[j].w;
            if(w || col[v]!=1 || scc[u]==scc[v]) continue;
            ans.emp(make_pair(min(u,v), max(u,v)));
        }
    }

    sort(ans.begin(), ans.end());
    printf("%ld\n", ans.size());
    for(auto cr: ans) printf("%d %d\n", cr.first, cr.second);
    return 0;
}