#include <bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll = long long;
const int kn = 6e5 + 65, mod = 998244353;

int n, a[kn];
ll f[kn][3], g[kn];

inline void _solv() {
    cin >> n;
    for (int i = 0; i <= 3 * n; i++) {
        f[i][0] = f[i][1] = f[i][2] = 0;
        g[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int x = a[i];

        g[x] = 1;
        f[x][0] = (g[x-2] + f[x-2][1] + f[x-2][2]) % mod;
        f[x][1] = (f[x-1][0] + g[x-1]) % mod;
        f[x][2] = f[x-1][1];

        ans = (ans + g[x] + f[x][0] + f[x][1] + f[x][2]) % mod;
        ans = (ans + i - 1 - g[x-1] - g[x-2]) % mod;
//        printf("%d: %lld %lld %lld %lld\n", x, g[x], f[x][0], f[x][1], f[x][2]);
    }

    printf("%lld\n", (ans + mod) % mod);
}
signed main() {
    int T; cin >> T;
    while (T--) {
        _solv();
    }
}
