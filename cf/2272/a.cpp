#include <bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll = long long;
const int kn = 2e5 + 25;

int n, m, a[kn], pos[kn];

inline void _solv() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    int ansx = -1, ansy = -1, p = n - m + 1;
    for (int i = 0; i < p; ++i) {
        if (pos[i] > p) {
            ansx = pos[i];
            for (int j = n - 1; j > i; j--) {
                if (pos[j] <= p) {
                    ansy = pos[j];
                    break;
                }
            }
            if (ansx > ansy) swap(ansx, ansy);
            break;
        }
    }

    if (ansx == -1 || ansy == -1) printf("-1\n");
    else printf("%d %d\n", ansx, ansy);
}

signed main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) _solv();
    return 0;
}
