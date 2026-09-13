#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn = 1e5 + 15;
int n, d;
class Book{
    public: int h, w;
}a[kn];
ll f[kn], sumw[kn];

class SGT{
    public: ll v[kn<<2], t[kn<<2];
    inline void pu(int u){
        int ls = u<<1, rs = u<<1|1;
        v[u] = min(v[ls], v[rs]);
    }
    inline void pd(int u){
        int ls = u<<1, rs = u<<1|1;
        t[ls] += t[u];
        t[rs] += t[u];
        v[ls] += t[u];
        v[rs] += t[u];
        t[u] = 0;
    }
    void bud(int u, int l, int r){
        if(l == r){ v[u] = t[u] = 0; return; }
        int md = (l+r)>>1, ls = u<<1, rs = u<<1|1;
        bud(ls, l, md);
        bud(rs, md+1, r);
        pu(u);
    }
    void upd(int u, int l, int r, int x, int y, ll w){
        if(l == x && r == y){ v[u] += w; t[u] += w; return; }
        pd(u);
        int md = (l+r)>>1, ls = u<<1, rs = u<<1|1;
        if(y <= md) upd(ls, l, md, x, y, w);
        else if (x > md) upd(rs, md+1, r, x, y, w);
        else{ upd(ls, l, md, x, md, w); upd(rs, md+1, r, md+1, y, w); }
        pu(u);
    }
    ll qry(int u, int l, int r, int x, int y){
        if(l == x && r == y) return v[u];
        pd(u);
        int md = (l+r)>>1, ls = u<<1, rs = u<<1|1;
        if(y <= md) return qry(ls, l, md, x, y);
        else if (x > md) return qry(rs, md+1, r, x, y);
        else return min(qry(ls, l, md, x, md), qry(rs, md+1, r, md+1, y));
    }
}G;

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> d;
    for(int i=1; i<=n; ++i){
        cin >> a[i].h >> a[i].w;
        sumw[i] = sumw[i-1] + a[i].w;
    }
    G.bud(1, 0, n);
    memset(f, 0x3f, sizeof f); // ++
    f[0] = 0;
    stack<int> stk;
    for(int i=1; i<=n; ++i){
        while(!stk.empty() && a[stk.top()].h < a[i].h){
            int j = stk.top(); stk.pop();
            int pj = stk.empty() ? 0 : stk.top();
            G.upd(1, 0, n, pj, j-1, -a[j].h);
        }
        int pj = stk.empty() ? 0 : stk.top();
        G.upd(1, 0, n, pj, i-1, a[i].h);
        stk.push(i); // ++
        int j = lower_bound(sumw, sumw + i, sumw[i] - d) - sumw;
        f[i] = G.qry(1, 0, n, j, i-1);
        G.upd(1, 0, n, i, i, f[i]);
    }
    printf("%lld\n", f[n]);
    return 0;
}