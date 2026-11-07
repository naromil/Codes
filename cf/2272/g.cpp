#include <bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll = long long;
const int kn = 2e5 + 25;

int n, m, q, ans[kn];
int id[kn], tt = 0, start[kn<<1];
pair<int, int> E[kn<<1];

class DSU {
public:
    int fu[kn], sz[kn], sum = 0;
    stack<pair<int, int>> stk;

    inline void init() {
        for (int i = 0; i <= n; i++) {
            fu[i] = i;
            sz[i] = 1;
        }
        while (!stk.empty()) stk.pop();
        sum = 0;
    }

    int find(int u) {
        return fu[u] == u ? u : find(fu[u]);
    }

    inline void join(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return;
        if (sz[fx] > sz[fy]) swap(fx, fy);

        fu[fx] = fy;
        sz[fy] += sz[fx];
        sum++;
        stk.push(make_pair(fx, fy));
    }

    inline void rewind() {
        int fx = stk.top().first, fy = stk.top().second;
        stk.pop();
        fu[fx] = fx;
        sz[fy] -= sz[fx];
        sum--;
    }
}D;

class Segtree {
public:
    vector<int> t[kn<<2];

    void build(int u, int l, int r) {
        t[u].clear();
        if (l == r) return;
        int md = (l+r)>>1, ls = u<<1, rs = u<<1|1;
        build(ls, l, md);
        build(rs, md + 1, r);
    }

    void upd(int u, int l, int r, int x, int y, int w) {
        if (y < l || r < x) return;
        if (x <= l && r <= y) {
            t[u].emp(w);
            return;
        }
        int md = (l+r)>>1, ls = u<<1, rs = u<<1|1;
        upd(ls, l, md, x, y, w);
        upd(rs, md + 1, r, x, y, w);
    }

    void dfs(int u, int l, int r) {
        int top = D.stk.size();
        for (auto e : t[u]) {
            int x = E[e].first, y = E[e].second;
            D.join(x, y);
        }

        if (l == r) {
            ans[l] = D.sum;
        }
        else {
            int md = (l+r)>>1, ls = u<<1, rs = u<<1|1;
            dfs(ls, l, md);
            dfs(rs, md + 1, r);
        }

        while (D.stk.size() > top) {
            D.rewind();
        }
    }
}G;

inline void _solv() {
    cin >> n >> m >> q;
    n++;
    tt = 0;
    G.build(1, 0, q);
    D.init();

    for (int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        E[++tt] = make_pair(x, y + 1);
        start[tt] = 0;
        id[i] = tt;
    }

    for (int i = 1; i <= q; i++) {
        int j, x, y; cin >> j >> x >> y;
        int l = start[id[j]], r = i - 1;
        G.upd(1, 0, q, l, r, id[j]);

        E[++tt] = make_pair(x, y + 1);
        start[tt] = i;
        id[j] = tt;
    }

    for (int i = 1; i <= m; i++) {
        int l = start[id[i]], r = q;
        G.upd(1, 0, q, l, r, id[i]);
    }

    G.dfs(1, 0, q);

    for (int i = 0; i <= q; i++) {
        printf("%d\n", ans[i]);
    }
}
signed main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) _solv();
    return 0;
}

