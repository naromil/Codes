#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e5 + 25;
int n, q, a[kn], dep[kn], fa[kn][22], rp[kn];
vector<int> c[kn];

int o[kn];
class SGT{
    public: int t[kn*36], ls[kn*36], rs[kn*36], tt = 0;
    inline void pu(int u){
        t[u] = t[ls[u]] + t[rs[u]];
    }
    void upd(int &u, int l, int r, int x){
        t[++tt] = t[u];
        ls[tt] = ls[u];
        rs[tt] = rs[u];
        u = tt;
        if(l == r){ ++t[u]; return; }
        int md = (l+r)>>1;
        if(x <= md) upd(ls[u], l, md, x);
        else upd(rs[u], md+1, r, x);
        pu(u);
    }
    int qry(int L, int R, int A, int B, int l, int r, int rnk){
        if(l == r) return l;
        int val = t[ls[L]] + t[ls[R]] - t[ls[A]] - t[ls[B]], md = (l+r)>>1;
        if(val >= rnk) return qry(ls[L], ls[R], ls[A], ls[B], l, md, rnk);
        else return qry(rs[L], rs[R], rs[A], rs[B], md+1, r, rnk - val);
    }
}G;

void dfs(int u, int b){
    dep[u] = dep[b] + 1;
    fa[u][0] = b;
    o[u] = o[b];
    G.upd(o[u], 1, 1e5, a[u]);
    for(int i=1; i<20; ++i) fa[u][i] = fa[fa[u][i-1]][i-1];
    for(auto v: c[u]){
        if(v == b) continue;
        dfs(v, u);
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

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> q;
    vector<int> a0;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        a0.emp(a[i]);
    }
    sort(a0.begin(), a0.end());
    int a0siz = unique(a0.begin(), a0.end()) - a0.begin();
    while(a0.size() > a0siz) a0.pop_back();
    for(int i=1; i<=n; ++i){
        int w = a[i];
        a[i] = lower_bound(a0.begin(), a0.end(), a[i]) - a0.begin() + 1;
        rp[a[i]] = w;
    }

    for(int i=1; i<n; ++i){
        int x, y; cin >> x >> y;
        c[x].emp(y);
        c[y].emp(x);
    }
    dfs(1, 0);

    for(int i=1,lst=0; i<=q; ++i){
        int x, y, k; cin >> x >> y >> k; x ^= lst;
        int g = lca(x, y);
        lst = rp[G.qry(o[x], o[y], o[g], o[fa[g][0]], 1, 1e5, k)];
        printf("%d\n", lst);
    }
    return 0;
}