#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 3e5 + 35;
const ll linf = 0x3f3f3f3f3f3f3f3f;
int n, q;
ll a[kn];
class SGT{
    public: ll t[kn<<2], v[kn<<2], mn[kn<<2];
    inline void pu(int u){
        int ls = u<<1, rs = u<<1|1;
        t[u] = t[ls] + t[rs];
        mn[u] = min(mn[ls], mn[rs]);
    }
    inline void pd(int u, int l, int r){
        if(!v[u]) return;
        int md = (l+r)>>1, ls = u<<1, rs = u<<1|1;
        mn[ls] += v[u];
        mn[rs] += v[u];
        v[ls] += v[u];
        v[rs] += v[u];
        v[u] = 0;
    }
    void bud(int u, int l, int r){
        if(l == r){
            t[u] = 1; // =a[l] -> =1
            v[u] = 0;
            mn[u] = a[l];
            return;
        }
        int md = (l+r)>>1, ls = u<<1, rs = u<<1|1;
        bud(ls, l, md);
        bud(rs, md+1, r);
        pu(u);
    }
    ll upd(int u, int l, int r, int x, int y, ll w){
        int md = (l+r)>>1, ls = u<<1, rs = u<<1|1;
        ll res = 0;
        if(l == x && r == y && mn[u] > w){
            mn[u] -= w;
            v[u] -= w;
            return w * t[u];
        }
        else if(l == r){
            res = mn[u];
            t[u] = 0;
            mn[u] = linf;
            return res;
        }
        pd(u, l, r);
        if(y <= md) res = upd(ls, l, md, x, y, w);
        else if(x > md) res = upd(rs, md+1, r, x, y, w);
        else res = upd(ls, l, md, x, md, w) + upd(rs, md+1, r, md+1, y, w);
        pu(u);
        return res;
    }
}G;

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
    }
    G.bud(1, 1, n);
    cin >> q;
    for(int i=1; i<=q; ++i){ // n -> q
        int x, y; ll w; cin >> x >> y >> w;
        ll res = G.upd(1, 1, n, x, y, w);
        printf("%lld\n", res);
    }
    return 0;
}
