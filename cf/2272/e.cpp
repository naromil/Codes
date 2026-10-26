#include <bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll = long long;
const int kn = 2e5 + 25;

int n, m, s0[kn], s1[kn];
string a, b;

inline void _solv2() {
    vector<int> w;
    for (int j = 1; j <= m; j++){
        if (b[j] == 'W') w.push_back(j);
    }

    vector<ll> g;
    for (int k = 0; k + 1 < w.size(); k++) {
        g.push_back(w[k+1] - w[k]);
    }
    sort(g.begin(), g.end());

    vector<ll> pre(g.size() + 1, 0);
    for (int k = 0; k < g.size(); k++){
        pre[k+1] = pre[k] + g[k];
    }

    int p = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 'W') { p = i; continue; }
        ll ans;
        if (p > 0) {
            ans = m + 1;
            if (!w.empty()) ans = max<ll>(m, w.back() + i - 1 - p) + 1;
        }
        else if (w.empty()) {
            ans = 1;
        }
        else {
            ll L = i;
            int c = lower_bound(g.begin(), g.end(), L) - g.begin();
            ans = 1 + L + pre[c] + (ll)(g.size() - c) * L;
        }
        printf("%lld ", ans);
    }
    printf("\n");
}

inline void _solv() {
    cin >> n >> m >> a >> b;
    a = " " + a;
    b = " " + b;
    _solv2();
    swap(n, m);
    swap(a, b);
    _solv2();
}
signed main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) _solv();
    return 0;
}
