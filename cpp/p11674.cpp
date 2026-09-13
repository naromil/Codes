#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e5 + 25;
int n, m, fu[kn], sz[kn];
vector<int> c[kn];
string a;
ll ans = 0;
int find(int x){ return fu[x] == x ? x : fu[x] = find(fu[x]); }
inline ll calc(int x){ return ((x - 1ll) * x) >> 1; }
inline void unionn(int x, int y){
    int fx = find(x), fy = find(y);
    if(fx == fy) return;
    fu[fy] = fx;
    ans = ans - calc(sz[fx]) - calc(sz[fy]) + calc(sz[fx] + sz[fy]);
    sz[fx] += sz[fy];
}

vector<int> vec[kn];
signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> m >> a;
    a = " " + a;
    for(int i=1; i<=m; ++i){
        int x, y; cin >> x >> y;
        c[x].emp(y);
        c[y].emp(x);
    }
    for(int i=1; i<=n; ++i) fu[i] = i;
    for(int u=1; u<=n; ++u){
        if(a[u] == '1'){
            for(auto v: c[u]){
                if(a[v] == '1') unionn(u, v);
                else vec[v].emp(u);
            }
        }
    }

    stack<ll> stk;
    for(int u=n; u>=1; --u){
        int fx = find(u);
        ans = ans - calc(sz[fx]) + calc(sz[fx] + 1);
        ++sz[fx];
        for(auto v: vec[u]){
            unionn(u, v);
        }
        for(auto v: c[u]){
            if(v > u) unionn(u, v);
        }
        stk.push(ans);
    }
    while(!stk.empty()) printf("%lld\n", stk.top()), stk.pop();
    return 0;
}