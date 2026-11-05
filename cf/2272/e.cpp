#include <bits/stdc++.h>
#include <cassert>
#define emp emplace_back
using namespace std;
using ll = long long;
const int kn = 2e5 + 25;

int n, m;
string a, b;

inline void _solv2() {

    vector<int> g;
    vector<ll> sum;
    int lst = -1e9;
    for (int i = 1; i <= m; i++) {
        if (b[i] == 'W') {
            if (lst > 0) g.emp(i - lst);
            lst = i;
        }
    }

    sort(g.begin(), g.end());
    for (int i = 0; i < g.size(); i++) sum.emp(g[i]);
    for (int i = 1; i < g.size(); i++) sum[i] += sum[i-1];

    int x = -1e9;
    vector<ll> ans;
    for (int i = 1; i <= n; i++) {
        if (a[i] != 'R') {
            x = i;
            continue;
        }

        if (x > 0) {
            int rt = max(x + m, lst + i - 1);
            ans.emp(rt - x + 1);
        }
        else {
            if (lst > 0) {
                int mt = lower_bound(g.begin(), g.end(), i) - g.begin();
                ll pre = (mt == 0) ? 0 : sum[mt-1];
                ans.emp(1 + pre + (g.size() - mt + 1ll) * 1ll * i);
            }
            else {
                ans.emp(1);
            }
        }
    }

    for (auto y : ans) {
        printf("%lld ", y);
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
