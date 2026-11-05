#include <bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll = long long;
const int kn = 5e5 + 25;

int n, f[kn][2], dp[kn][2];
vector<int> c[kn];

void dfs(int u, int b) {
    f[u][0] = f[u][1] = 0;

    for (auto v : c[u]) {
        if (v == b) continue;
        dfs(v, u);

        if (f[v][0] + f[v][1] == 0) f[u][0]++;
    }

    if (c[u].size() % 2 == 1) f[u][1] = 1;
}

void dfs2(int u, int b) {

    for(auto v : c[u]) {
        if (v == b) continue;

        bool vtmp = (f[v][0] + f[v][1] == 0);
        bool tmp = (dp[u][0] - vtmp == 0 && dp[u][1] == 0);

        dp[v][0] = f[v][0] + tmp;
        dp[v][1] = (c[v].size() % 2 == 1);

        dfs2(v, u);
    }
}

inline void _solv() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        c[i].clear();
    }

    for (int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        c[x].emp(y);
        c[y].emp(x);
    }

    dfs(1, 0);

    dp[1][0] = f[1][0];
    dp[1][1] = f[1][1];
    dfs2(1, 0);

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (dp[i][0] + dp[i][1] == 0) ans.emp(i);
        // printf("%d: %d %d\n", i, dp[i][0], dp[i][1]);
    }

    if (ans.empty()) {
        printf("Alice\n");
    }
    else {
        printf("Bob\n%ld\n", ans.size());
        for (auto x : ans) printf("%d ", x);
        printf("\n");
    }
}
signed main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) _solv();
    return 0;
}
