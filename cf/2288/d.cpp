#include <bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll = long long;
const int kn = 2e5 + 25;

int n, a[kn];

inline bool chk(ll md) {
    int l, r;
    ll suf = a[n], pre = a[1];
    for (l = n - 1; l >= 1; l--) {
        suf += a[l];
        if (suf > md) break;
    }
    for (r = 2; r <= n; r++) {
        pre += a[r];
        if (pre > md) break;
    }
    ll sum = 0;
    for (int i = 1; i <= l; i++) sum += a[i];
    for (int i = r; i <= n; i++) sum += a[i];
    return sum <= md;
}

inline void _solv() {
    cin >> n;
    a[n + 1] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll lt = 1, rt = 1e18, at = 1e18;
    while (lt <= rt) {
        ll md = (lt + rt) >> 1;
        if (chk(md)) rt = md - 1, at = md;
        else lt = md + 1;
    }

    printf("%lld\n", at);
}
signed main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) _solv();
    return 0;
}
