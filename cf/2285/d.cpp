#include <bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll = long long;
const int kn = 3e5 + 35, mod = 1e9 + 7;

int n, m, q, a[kn], b[kn];
ll c[kn], jc[kn], ijc[kn];
inline int fpow(ll x, int y) {
    int res = 1;
    while (y > 0) {
        if (y & 1) res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}
inline ll calc(int cnt) {
    if (cnt >= m) return jc[cnt - 1] * ijc[m - 1] % mod * ijc[cnt - m] % mod;
    else return 0;
}

struct Query {
    int x, w, l, i;
    bool operator < (const Query &v) const { return l > v.l; }
} qs[kn];
ll ans[kn];

inline void _solv() {
    cin >> n >> m >> q;
    jc[0] = ijc[0] = 1;
    for (int i = 1; i <= n; i++) jc[i] = jc[i - 1] * i % mod;
    ijc[n] = fpow(jc[n], mod - 2);
    for (int i = n - 1; i >= 1; i--) ijc[i] = ijc[i + 1] * (i + 1) % mod;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[n - i + 1] = a[i];
    }

    ll suma = 0, sumb = 0;
    int cntt = 0;
    for (int i = 1; i <= n; i++) {
        suma += a[i];
        sumb += b[i];
        c[i] = sumb - suma;
        if (c[i] == 0) cntt++;
    }

    for (int i = 1; i <= q; i++) {
        cin >> qs[i].x >> qs[i].w;
        qs[i].l = min(qs[i].x, n - qs[i].x + 1);
        qs[i].i = i;
    }
    sort(qs + 1, qs + q + 1);

    map<ll, int> cnt;
    int l = (n + 1) / 2;
    if (n % 2 == 0) cnt[c[l]]++;
    for (int i = 1; i <= q; i++) {
        while (l > qs[i].l) {
            cnt[c[n - l + 1]]++;
            cnt[c[--l]]++;
        }
        if (qs[i].x <= n - qs[i].x + 1) {
            ans[qs[i].i] = calc(cntt - cnt[0] + cnt[qs[i].w]);
        }
        else {
            ans[qs[i].i] = calc(cntt - cnt[0] + cnt[-qs[i].w]);
        }
    }

    for (int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
}
signed main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) _solv();
    return 0;
}

