#include <bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll = long long;
const int kn = 2e5 + 25;

int n, m, a[kn];

inline void _solv() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = (a[i] + m - 1) / m;
    }
    sort(a + 1, a + n + 1);

    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans = max(ans, a[i] - i);
    }
    printf("%d\n", ans);
}
signed main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) _solv();
    return 0;
}
