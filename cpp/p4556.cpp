#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e5 + 25;
int n, m, dep[kn], fa[kn][20];
vector<int> c[kn];

int o[kn];
class SGT{
    public: int tt = 0, t[kn*36], mx[kn*36], ls[kn*36], rs[kn*36];
    inline void pu(int u){
        t[u] = max(t[ls[u]], t[rs[u]]);
        mx[u] = (t[ls[u]] == t[u]) ? mx[ls[u]] : mx[rs[u]];
    }
    void upd(int &u, int l, int r, int x, int w){
        if(!u) u = ++tt;
        if(l == r){ t[u] += w; mx[u] = l; return; }
        int md = (l+r)>>1;
        if(x <= md) upd(ls[u], l, md, x, w);
        else upd(rs[u], md+1, r, x, w);
        pu(u);
    }
    int mrg(int u, int v, int l, int r){
        if(!u || !v) return u | v;
        if(l == r){ t[u] += t[v]; mx[u] = l; return u; }
        int md = (l+r)>>1;
        ls[u] = mrg(ls[u], ls[v], l, md);
        rs[u] = mrg(rs[u], rs[v], md+1, r);
        pu(u);
        return u;
    }
}G;

void dfs1(int u, int b){
    dep[u] = dep[b] + 1;
    fa[u][0] = b;
    for(int i=1; i<20; ++i) fa[u][i] = fa[fa[u][i-1]][i-1];
    for(auto v: c[u]){
        if(v == b) continue;
        dfs1(v, u);
    }
}
inline int lca(int x, int y){
    if(dep[x] < dep[y]) swap(x, y);
    for(int i=19; i>=0; --i){
        if(dep[fa[x][i]] >= dep[y]) x = fa[x][i];
    }
    if(x == y) return y;
    for(int i=19; i>=0; --i){
        if(fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
    }
    return fa[y][0];
}

int ans[kn];
void dfs2(int u, int b){
    for(auto v: c[u]){
        if(v == b) continue;
        dfs2(v, u);
        o[u] = G.mrg(o[u], o[v], 1, 1e5); // + o[u]=
    }
    ans[u] = G.t[o[u]] ? G.mx[o[u]] : 0;
}

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1; i<n; ++i){
        int x, y; cin >> x >> y;
        c[x].emp(y);
        c[y].emp(x);
    }
    dfs1(1, 0);

    for(int i=1; i<=m; ++i){
        int x, y, z; cin >> x >> y >> z;
        int l = lca(x, y);
        G.upd(o[x], 1, 1e5, z, 1);
        G.upd(o[y], 1, 1e5, z, 1);
        G.upd(o[l], 1, 1e5, z, -1);
        G.upd(o[fa[l][0]], 1, 1e5, z, -1);
    }

    dfs2(1, 0);
    for(int i=1; i<=n; ++i){
        printf("%d\n", ans[i]);
    }
    return 0;
}