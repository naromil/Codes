#include<bits/stdc++.h>
#define x first
#define y second
#define mkp make_pair
#define pii pair<int,int>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e4 + 24, inf = 0x3f3f3f3f;
int n, m, D[kn], C[kn], S[kn], W[kn], f[kn][108];
class SGT{
    public: int t[kn<<2], v[kn<<2];
    inline void pu(int u){
        int ls = u<<1, rs = u<<1|1;
        t[u] = min(t[ls], t[rs]);
    }
    inline void pd(int u){
        int ls = u<<1, rs = u<<1|1;
        t[ls] += v[u]; t[rs] += v[u];
        v[ls] += v[u]; v[rs] += v[u];
        v[u] = 0;
    }
    void ini(int u, int l, int r, int k){
        v[u] = 0;
        if(l == r){
            t[u] = f[l][k];
            return;
        }
        int md = (l+r)>>1, ls = u<<1, rs = u<<1|1;
        ini(ls, l, md, k);
        ini(rs, md+1, r, k);
        pu(u);
    }

    void upd(int u, int l, int r, int x, int y, int w){
        if(l > x || x > y || y > r) return;
        if(l == x && r == y){
            t[u] += w;
            v[u] += w;
            return;
        }
        pd(u);
        int md = (l+r)>>1, ls = u<<1, rs = u<<1|1;
        if(y <= md) upd(ls, l, md, x, y, w);
        else if(x > md) upd(rs, md+1, r, x, y, w);
        else upd(ls, l, md, x, md, w), upd(rs, md+1, r, md+1, y, w);
        pu(u);
    }
    int qry(int u, int l, int r, int x, int y){
        if(l > x || x > y || y > r) return 0;
        if(l == x && r == y) return t[u];
        pd(u);
        int md = (l+r)>>1, ls = u<<1, rs = u<<1|1;
        if(y <= md) return qry(ls, l, md, x, y);
        else if(x > md) return qry(rs, md+1, r, x, y);
        else return min(qry(ls, l, md, x, md), qry(rs, md+1, r, md+1, y));
    }
}G;

vector<pii> nxt;
inline void _init(){
    cin >> n >> m;
    for(int i=2; i<=n; ++i) cin >> D[i];
    for(int i=1; i<=n; ++i) cin >> C[i];
    for(int i=1; i<=n; ++i) cin >> S[i];
    for(int i=1; i<=n; ++i) cin >> W[i];
    ++m; ++n;
    D[n] = W[n] = inf;
    for(int i=1; i<=n; ++i) nxt.emp(mkp(D[i] + S[i], i));
    sort(nxt.begin(), nxt.end());
    memset(f, 0x3f, sizeof f);
    for(int i=1,j=0,sum=0; i<=n; ++i){
        while(j < nxt.size() && nxt[j].x < D[i]){
            sum += W[nxt[j++].y];
        }
        f[i][1] = sum + C[i];
    }
}

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    _init();
    int ans = f[n][1];
    for(int k=2; k<=m; ++k){
        G.ini(1, 1, n, k-1);
        for(int i=1,j=0; i<=n; ++i){
            while(j < nxt.size() && nxt[j].x < D[i]){
                int pr = nxt[j++].y, os = lower_bound(D + 1, D + n + 1, D[pr] - S[pr]) - D - 1;
                G.upd(1, 1, n, 1, os, W[pr]);
            }
            f[i][k] = G.qry(1, 1, n, 1, i-1) + C[i];
        }
        ans = min(ans, f[n][k]);
    }
    printf("%d\n", ans);
    return 0;
}