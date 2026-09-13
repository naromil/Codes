#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 1e5 + 15;
int n, E[kn];
ll p, q, a[kn], sz[kn], sum = 0, ans = 0, num = 0;
vector<int> c[kn];
class SGT{
    public:
    static const ll bd = 1e11;
    ll t[kn*42], v[kn*42];
    int ls[kn*42], rs[kn*42], o = 0, tt = 0;
    inline void pu(int u, ll l, ll r){
        ll md = (l+r)>>1;
        t[u] = t[ls[u]] + t[rs[u]];
        v[u] = min(v[ls[u]], v[rs[u]] + t[ls[u]] + (md - l + 1) * p);
    }
    void upd(int &u, ll l, ll r, ll x, ll w){
        if(!u) u = ++tt;
        if(l == r){ t[u] += w; v[u] = t[u] + p; return; }
        ll md = (l+r)>>1;
        if(x <= md) upd(ls[u], l, md, x, w);
        else upd(rs[u], md+1, r, x, w);
        pu(u, l, r);
    }
    inline void U(ll x, ll w){ upd(o, 1, bd, x, w); }
    inline void clear(){
        for(int i=1; i<=tt; ++i)
            t[i] = v[i] = ls[i] = rs[i] = 0;
        o = tt = 0;
    }
}G;

void dfs0(int u, int b){
    sz[u] = a[u];
    for(auto v: c[u]){
        if(v == b) continue;
        dfs0(v, u);
        sz[u] += sz[v];
        if(sz[v]) ++E[u];
    }
    if(sz[u] < sum) ++E[u];
    if(a[u]) E[u] = 1e9;
    if(E[u] > 2) G.U(sz[u], -q), G.U(1, q);
}

void dfs1(int u, int b){
    if(E[u] > 2) G.U(sz[u], q);
    else G.U(1, q);
    ans = min(ans, G.v[G.o]);
    if(E[u] > 2) G.U(sz[u], -q);
    else G.U(1, -q);

    if(E[u] > 2) G.U(sz[u], q);
    for(auto v: c[u]){
        if(v == b || !sz[v]) continue;
        if(E[u] > 2) G.U(sum - sz[v], -q);
        dfs1(v, u);
        if(E[u] > 2) G.U(sum - sz[v], q);
    }
    if(E[u] > 2) G.U(sz[u], -q);
}

inline void _solv(){
    cin >> n >> p >> q;
    G.clear();
    sum = num = 0;
    for(int i=1; i<=n; ++i){
        c[i].clear();
        E[i] = 0;

        cin >> a[i];
        if(a[i]) ++num;
        sum += a[i];
    }
    for(int i=1; i<n; ++i){
        int x, y; cin >> x >> y;
        c[x].emp(y);
        c[y].emp(x);
    }
    if(!num){ printf("0\n"); return; }

    ans = num * q;
    dfs0(1, 0);
    dfs1(1, 0);
    printf("%lld\n", ans);
}
signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) _solv();
    return 0;
}