#include <bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll = long long;
const int kn = 3e5 + 35, mod = 1e9 + 7;

int n, a[kn];

inline int fpow(ll x, int y) {
    int res = 1;
    while (y > 0) {
        if (y & 1) res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

inline void _solv() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    a[n + 1] = 0;

    int lst = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i] == a[i-1]) lst = i;
    }

    ll ans = 0;
    for (int i = lst; i <= n; i++) {
        if (a[i] == a[i+1]) continue;
        ans = (ans + fpow(a[i + 1] - 1, n - i)) % mod;
    }

    printf("%lld\n", (ans % mod + mod) % mod);
}
signed main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) _solv();
    return 0;
}
