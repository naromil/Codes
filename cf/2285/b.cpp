#include <bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll = long long;
const int kn = 3e5 + 35;

int n, m;
string a;

ll calc(int num) {
    return num * (num - 1ll) / 2ll + num;
}

inline void _solv() {
    cin >> n >> m >> a;
    a = " " + a;
    int num0 = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == '0') num0++;
    }

    ll x = num0, y = n - num0;
    if (x < y) swap(x, y);
    x = min<ll>(n, x + m);
    y = max<ll>(0, y - m);
    printf("%lld\n", calc(x) + calc(y) + 1);
}
signed main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) _solv();
    return 0;
}

