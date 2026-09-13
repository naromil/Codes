#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e5 + 25, mod = 998244353;
int n;
vector<int> c[kn];

vector<ll> f[kn];
ll dp[1<<21];
void dfs(int u, int b){
    if(c[u].empty()){ f[u] = {1, 1}; return; }
    for(auto v: c[u]) dfs(v, u);
    sort(c[u].begin(), c[u].end(), [](int x, int y){ return f[x].size() < f[y].size(); });
    int son = c[u].back();
    c[u].pop_back();

    int lst = 0;
    dp[0] = 1;
    if(!c[u].empty()){
        fill(dp, dp + (1<<f[c[u].back()].size()), 0);
        dp[0] = 1;
        for(auto v: c[u]){
            for(int k=(1<<lst)-1; k>=0; --k) if(dp[k]){
                ll w = dp[k]; dp[k] = 0;
                for(int j=0; j<f[v].size(); ++j){
                    (dp[k|1<<j] += w * f[v][j]) %= mod;
                }
            }
            lst = f[v].size();
        }
    }
    
    f[u].resize(f[son].size() + 1);
    for(int j=0; j<f[son].size(); ++j){
        for(int k=0; k<(1<<lst); ++k){
            int x = ~(k|1<<j); x = log2(-x & x);
            (f[u][x] += dp[k] * f[son][j]) %= mod;
        }
    }
    if(f[u].back() == 0) f[u].pop_back();
}

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n;
    for(int i=2,x; i<=n; ++i){
        cin >> x;
        c[x].emp(i);
    }
    dfs(1, 0);
    for(int j=0; j<min(n+1, (signed)f[1].size()); ++j){
        printf("%lld\n", f[1][j]);
    }
    for(int j=f[1].size(); j<n+1; ++j) printf("0\n");
    return 0;
}