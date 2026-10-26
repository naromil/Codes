#include <bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll = long long;
const int kn = 2e5 + 25;

int n, m, a[kn];

inline int dist(int x, int y, int mt) {
    if (x > y) swap(x, y);
    return (y - x - 1) / mt;
}

// @return minimum required extra points
inline int chk(int mt) {
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        if (i > 1 && dist(a[i], a[i-1], mt) == 0) continue;
        else if (i < n && dist(a[i], a[i+1], mt) == 0) continue;
        v.emp(a[i]);
    }

    int ans = v.size();

    vector<bool> used(v.size());
    for (int i = 1; i < v.size(); i++) {
        if (dist(v[i], v[i-1], mt) == 1 && !used[i-1]) {
            used[i-1] = used[i] = true;
            ans--;
        }
    }

    return ans;
}

inline void _solv() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int lt = 1, rt = 1e9, at = 1e9;
    while (lt <= rt) {
        int mt = (lt + rt) >> 1;
        if (chk(mt) <= m) {
            rt = mt - 1;
            at = mt;
        }
        else {
            lt = mt + 1;
        }
    }

    printf("%d\n", at);
}

signed main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) _solv();
    return 0;
}

