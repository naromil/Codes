#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 1e6 + 16, mod = 1e6 + 3;
class SGT{
    public: ll t[kn<<2], v[kn<<2];
    inline void pu(int u){
        int ls = u<<1, rs = u<<1|1;
        t[u] = max(t[ls], t[rs]);
    }
    inline void pd(int u){
        int ls = u<<1, rs = u<<1|1;
        v[ls] += v[u];
        v[rs] += v[u];
        t[ls] += v[u];
        t[rs] += v[u];
        v[u] = 0;
    }
    void upd(int u, int l, int r, int x, int y, int w){
        if(y < l || r < x) return;
        else if(x <= l && r <= y){ t[u] += w; v[u] += w; return; }
        pd(u);
        int md = (l+r)>>1, ls = u<<1, rs = u<<1|1;
        if(x <= md) upd(ls, l, md, x, y, w);
        if(y > md) upd(rs, md+1, r, x, y, w);
        pu(u);
    }

}G;

int q, qt = 0, ql[kn], qr[kn], cnt[kn];
signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> q;
    ll lst = 0;
    for(int cs=1; cs<=q; ++cs){
        char op; cin >> op;
        if(op == 'A'){
            int x, y; cin >> x >> y;
            ql[++qt] = x = (x + lst) % mod;
            qr[qt] = y = (y + lst) % mod;
            G.upd(1, 1, kn, 1, x, y);
            if(!cnt[x]++) G.upd(1, 1, kn, x, x, x - 1);
        }
        else{
            int i, x, y; cin >> i;
            i = (i + lst) % mod;
            x = ql[i];
            y = qr[i];
            G.upd(1, 1, kn, 1, x, -y);
            if(!--cnt[x]) G.upd(1, 1, kn, x, x, 1 - x);
        }
        lst = G.t[1];
        printf("%lld\n", lst);
    }
    return 0;
}