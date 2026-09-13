#include<bits/stdc++.h>
#define emp emplace_back
#define pii pair<int,int>
#define mkp make_pair
#define fst first
#define scd second
using namespace std;
using ll=long long;
const int kn = 1e6 + 16;
ll n;

int m = 0;
pair<int,int> del[kn];
void dac(const ll &k, const ll &bs, const int &len){
    ll l = (n * k) / bs + 1, r = (n * (k + 1) - 1) / bs;
    if(l > r || len > 20) return;
    dac(k * 3 - 2, bs * 3, len + 1);
    del[++m] = mkp(l, r);
    dac((k + 1) * 3 + 1, bs * 3, len + 1);
}

unordered_map<ll, int> mp;
int dfs(ll u){
    if(mp.count(u)) return mp[u];
    ll x = min(u, n - u) * 3;
    if(x > n) return mp[u] = -1;
    mp[u] = 1;
    return mp[u] = dfs(x);
}
signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n;
    dac(1, 3, 1);
    for(int i=0,j=1; i<=n; ++i){
        while(j <= m && del[j].fst <= i && i <= del[j].scd)
            i = del[j++].scd + 1;
        if(dfs(i) == 1) printf("%d\n", i);
    }
    return 0;
}