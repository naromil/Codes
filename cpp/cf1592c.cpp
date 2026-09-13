#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e5 + 25;
int n, m, a[kn], sum=0, f[kn], ans=0, dp[kn];
vector<int> c[kn];
void dfs(int u, int b){
    f[u] = a[u];
    dp[u] = 0;
    for(auto v: c[u]){
        if(v == b) continue;
        dfs(v, u);
        f[u] ^= f[v];
        dp[u] += dp[v];
    }
    if(u != 1 && f[u] == sum && dp[u] == 0) ++dp[u];
    else if(f[u] == 0 && dp[u]) ans = 1;
}
inline void _solv(){
    cin >> n >> m;
    sum = ans = 0;
    for(int i=0; i<=n+5; ++i){
        a[i] = 0;
        c[i].clear();
    }
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        sum ^= a[i];
    }
    for(int i=2; i<=n; ++i){
        int x, y; cin >> x >> y;
        c[x].emp(y);
        c[y].emp(x);
    }
    if(sum == 0){ printf("YES\n"); return; }
    dfs(1, 0);
    printf((m >= 3 && (dp[1] >= 2 || ans == 1)) ? "YES\n" : "NO\n");
}
signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    int T; cin >> T; while(T--) _solv();
    return 0;
}
