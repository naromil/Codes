#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e5 + 25;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int n, a[kn], b[kn], q, rp[kn];
pair<int,int> qs[kn];

ll f[kn][3], ans[kn];
inline void calc(int u, int w){
    int ls = u<<1, rs = u<<1|1;
    int d[3] = {b[u], b[u], b[u]};
    d[a[u] > w ? 2 : (a[u] == w ? 1 : 0)] = 0;
    if(ls > n){
        f[u][0] = d[0];
        f[u][1] = d[1];
        f[u][2] = d[2];
    }
    else{
        f[u][0] = f[u][1] = f[u][2] = inf;
        for(int i=0; i<=2; ++i) for(int j=0; j<=2; ++j) for(int k=0; k<=2; ++k){
            int nx;
            if(i <= j && j <= k || k <= j && j <= i) nx = j;
            else if(j <= i && i <= k || k <= i && i <= j) nx = i;
            else nx = k;
            f[u][nx] = min(f[u][nx], d[i] + f[ls][j] + f[rs][k]);
        }
    }
}

void dfs0(int u, int w){
    if((u<<1) <= n)
        dfs0(u<<1, w), dfs0(u<<1|1, w);
    calc(u, w);
}
void dfs1(int u, int w){
    calc(u, w);
    if(u > 1) dfs1(u>>1, w);
}

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i] >> b[i];
        rp[i] = i;
    }
    cin >> q;
    for(int i=1; i<=q; ++i){
        cin >> qs[i].first;
        qs[i].second = i;
    }
    sort(qs + 1, qs + q + 1);
    sort(rp + 1, rp + n + 1, [](int x, int y){ return a[x] < a[y]; });

    memset(f, 0x3f, sizeof f);
    dfs0(1, qs[1].first);
    for(int i=1,j=1,k=1; i<=q; ++i){
        while(k <= n && qs[i].first >= a[rp[k]]) dfs1(rp[k++], qs[i].first);
        while(j <= k && qs[i].first > a[rp[j]]) dfs1(rp[j++], qs[i].first);
        ans[qs[i].second] = f[1][1];
    }
    for(int i=1; i<=q; ++i) printf("%lld\n", ans[i]);
    return 0;
}