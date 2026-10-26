#include <bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll = long long;
const int kn = 2e5 + 25;

int m;

class Tree {

public:
    int n, pt;
    vector<array<int, 2>> f;
    vector<vector<int>> c;

    inline void run() {
        cin >> n;

        pt = 0;
        f.assign(n + 1, array<int, 2>());
        c.assign(n + 1, vector<int>());

        for (int i = 1; i < n; i++) {
            int x, y; cin >> x >> y;
            c[x].emp(y);
            c[y].emp(x);
        }

        dfs(1, 0);

        if (f[1][0] >= f[1][1]) {
            pt = 1;
        } else if (c[1].size() >= 1) {
            pt = c[1][0];
        }
    }

    inline void dfs(int u, int b) {
        f[u][0] = 0;
        f[u][1] = 1;
        for (auto v: c[u]) {
            if (v == b) continue;
            dfs(v, u);
            f[u][0] += max(f[v][0], f[v][1]);
            f[u][1] += f[v][0];
        }
    }
}t[kn];

inline void _solv() {
    cin >> m;
    pair<int, int> pt;
    for (int i = 1; i <= m; i++) {
        t[i].run();
        if (t[i].pt != 0) {
            pt = make_pair(i, t[i].pt);
        }
    }

    if (pt.first == 0) {
        pt = make_pair(1, 1);
    }

    for (int i = 1; i <= m; i++) {
        if (i == pt.first) continue;
        printf("%d %d %d %d\n", pt.first, pt.second, i, 1);
    }
}

signed main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) _solv();
    return 0;
}
