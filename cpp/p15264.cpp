#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 1e6 + 16, mod = 1e9 + 7;
int n, m, a[kn];
ll b[kn], t, ans[kn], L, R;
inline ll fpow(ll x, int y){ ll res = 1; while(y){ if(y & 1){ res = res * x % mod; } x = x * x % mod; y >>= 1; } return res; }

vector<ll> A, B;
inline void mulp(vector<ll> &c, ll p){
    for(int i=n-1; i>=0; --i){
        c[i] = (((i > 0) ? c[i-1] * (1 - p + mod) % mod : 0ll) + c[i] * p % mod) % mod;
    }
}
inline void divp(vector<ll> &c, ll p){
    if(p == 1) return;
    ll q = 1 - p + mod, iq = fpow(q, mod - 2), lst = c[n-1];
    c[n-1] = 0;
    for(int i=n-2; i>=0; --i){
        ll w = lst * iq % mod;
        lst = (c[i] - w * p % mod + mod) % mod;
        c[i] = w;
    }
    assert(lst == 0);
}

inline void _proc(){
    A.assign(n, 0);
    B.assign(n, 0);
    A[0] = B[0] = 1;
    for(int i=1; i<=n; ++i){
        if(i < n) mulp(B, b[i]);
        a[i+n] = a[i] + m;
        b[i+n] = b[i];
    }
    for(int i=1,j=1; i<=n; ++i){
        if(n > 1){
            if(i == j) divp(B, b[i]), ++j;
            else divp(A, b[i]);
            mulp(B, b[i+n-1]);
        }
        else ++j;
        while(j < i + n && a[j] - a[i] <= L){
            mulp(A, b[j]);
            divp(B, b[j++]);
        }
        ll res = 0;
        int x = (n - i + 1) % n, y;
        for(int k=0; k<n; ++k){
            y = (k - x + n) % n;
            res = (res + A[x] * B[y] % mod) % mod;
            x = (x - R + n) % n;
        }
        int na = (a[i] + t) % m;
        ans[na] = (ans[na] + b[i] * res % mod) % mod;
    }
}
inline void _solv(){
    cin >> n >> m >> t;
    for(int i=0; i<=m+5; ++i) ans[i] = 0;
    L = (t << 1) % m;
    R = ((t << 1) / m) % n; // + %n
    for(int i=1; i<=n; ++i) cin >> b[i];
    for(int i=1; i<=n; ++i) cin >> a[i];

    _proc();
    for(int i=1; i<=n; ++i){
        b[i] = (1 - b[i] + mod) % mod; // + %mod
        a[i] = (m - a[i]) % m; // %mod -> %m
    }
    reverse(a + 2, a + n + 1);
    reverse(b + 2, b + n + 1);
    reverse(ans + 1, ans + m);
    _proc();

    for(int i=m; i>=1; --i){
        if(i < m) printf(" ");
        printf("%lld", (ans[i%m] % mod + mod) % mod);
    }
    printf("\n");
}
signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) _solv();
    return 0;
}