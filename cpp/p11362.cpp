#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e5 + 25, mod = 1e9 + 7;
int n, m, a[kn], b[kn];
ll V;
inline ll fpow(ll x, int y){
    int res = 1;
    while(y){
        if(y & 1) res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}
inline ll calc(int x){
    return (fpow(V, x<<1) - fpow(V, x) + fpow(V, x-1) + mod) % mod;
}

map<int, int> vis;
inline void _solv(){
    cin >> n >> m >> V;
    bool flg = false;
    vis.clear();
    for(int i=1; i<=m; ++i){
        cin >> a[i] >> b[i];
        if(vis.count(a[i]) && vis[a[i]] != b[i]) flg = true;
        vis[a[i]] = b[i];
    }
    if(flg){ printf("0\n"); return; }
    sort(a + 1, a + m + 1);
    m = unique(a + 1, a + m + 1) - a - 1; // ++
    ll ans = fpow(V, (a[1] - 1) << 1) * fpow(V, (n - a[m]) << 1) % mod;
    for(int i=2; i<=m; ++i){
        ans = ans * calc(a[i] - a[i-1]) % mod;
    }
    printf("%lld\n", ans);
}
signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) _solv();
    return 0;
}