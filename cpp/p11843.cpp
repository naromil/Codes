#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 8e5 + 85, mod = 1e9 + 7;
int N, n = 0, m, q, a[kn];
class Query{ public: int l, r, k; }as[kn], qs[kn];
inline ll fpow(ll x, int y){ ll res = 1; while(y){ if(y & 1) res = res * x % mod; x = x * x % mod; y >>= 1; } return res; }
ll E[kn], s[kn], t[kn];

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> N >> m >> q;
    for(int i=1; i<=m; ++i){
        int l, r; cin >> l >> r;
        as[i] = {l, r + 1, 0};
        E[++n] = l;
        E[++n] = r + 1;
    }
    for(int i=1; i<=q; ++i){
        int l, r, k; cin >> l >> r >> k;
        qs[i] = {l, r + 1, (r - l + 1) - k};
        E[++n] = l;
        E[++n] = r + 1;
    }
    sort(E + 1, E + n + 1);
    n = unique(E + 1, E + n + 1) - E - 1;
    E[n+1] = N + 1;

    for(int i=1; i<=m; ++i){
        a[lower_bound(E + 1, E + n + 1, as[i].l) - E] ^= 1;
        a[lower_bound(E + 1, E + n + 1, as[i].r) - E] ^= 1;
    }
    for(int i=1; i<=n; ++i){
        a[i] ^= a[i-1];
        s[i] = s[i-1] + (a[i] ^ 1) * (E[i+1] - E[i]);
    }
    for(int i=n; i>=1; --i){
        t[i] = (t[i+1] + a[i] * (fpow(2, E[i+1] - E[i]) - 1) * fpow(2, E[n+1] - E[i+1]) % mod) % mod;
    }
//    for(int i=1; i<=n; ++i) printf("%d: %d %lld %lld\n", i, a[i], E[i], s[i]);

    for(int i=1; i<=q; ++i){
        int l = lower_bound(E + 1, E + n + 1, qs[i].l) - E;
        int r = lower_bound(E + 1, E + n + 1, qs[i].r) - E;
        int x = lower_bound(s + l, s + r, qs[i].k + s[l-1]) - s; // E -> s
        printf("%d %d %d: %d\n", l, r, qs[i].k, x);
        if(x == r){
            printf("%lld\n", fpow(2, E[r] - E[l] - qs[i].k) - 1);
        }
        else{
            ll ans = (t[x+1] - t[r] + mod) * fpow(fpow(2, E[n+1] - E[r]), mod - 2) % mod;
            ans += (fpow(2, E[x+1] - E[l] - s[x] + s[l-1]) - 1) * fpow(2, E[r] - E[x+1] + s[x] - s[l-1] - qs[i].k) % mod;
            printf("%lld\n", (ans + mod) % mod);
        }
    }

    return 0;
}