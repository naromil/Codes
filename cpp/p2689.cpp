#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 1e6 + 16;
int n, k, mod, m[kn], a[kn];
namespace data_gen{
    unsigned int s1, s2, s3;
    inline unsigned int next(){
        unsigned int res;
        s1 ^= s3;
        s3 += 3055373123u;
        res = s1;
        s2 = (s2 ^ s3) & 31;
        s3 = (s3 >> s2) | ((s3 << (31 ^ s2)) << 1);
        return res;
    }
    void main(){
        int M; cin >> n >> M >> k >> mod >> s1 >> s2 >> s3;
        for(int i=1; i<=n; ++i){
            m[i] = next() % M + 1;
            a[i] = next() % mod;
        }
    }
};

inline ll fpow(ll x, int y){
    int res = 1;
    while(y){
        if(y & 1) res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    data_gen::main();
    int iv2 = (mod + 1) >> 1;
    ll fp = 1, fn = 1;
    for(int i=1; i<=n; ++i){
        int M = m[i], A = a[i];
        fp = fp * fpow(1 + A, M) % mod;
        fn = fn * fpow(1 - A + mod, M) % mod;
    }
    ll f0 = (fp + fn) * iv2 % mod, f1 = (fp - f0 + mod) % mod;
    ll ans = f0;
    if(k) ans = (k + 1) * (f0 + f1) % mod * iv2 % mod;
    printf("%lld\n", ans);
    return 0;
}