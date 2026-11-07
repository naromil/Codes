#include <bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll = long long;
const int kn = 5e5 + 55;

int n, a[kn];
ll m, sum[kn];

inline void _solv() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i-1] + a[i];
    }

    ll ans = 0x3f3f3f3f3f3f3f3f;
    for (int v = 1e5; v >= 0; v--) {
        ll bd = (v != 0) ? (m - 1) / v : 0x3f3f3f3f3f3f3f3f;
        if (bd < v) continue;

        int x = lower_bound(a + 1, a + n, v) - a;
        ll cur = (sum[n-1] - sum[x-1]) - 1ll * v * (n - x);
//        printf("%d %lld\n", v, cur);
        cur += max(0ll, a[n] - bd);
        ans = min(ans, cur);
    }

    printf("%lld\n", ans);
}
signed main() {
    int T; cin >> T;
    while (T--) {
        _solv();
    }
}
