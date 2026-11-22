#include <bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll = long long;
const int kn = 5e4 + 54, n = 5e4;

struct Quest { int m, i; };
vector<Quest> ls[kn];
int ans[kn];

int f[kn];

signed main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        int x, y; cin >> x >> y;
        ls[x].emp(Quest{y, i});
    }
    for (int i = 1; i <= n; i++) {
        if (!ls[i].empty())
            sort(ls[i].begin(), ls[i].end(), [](Quest x, Quest y){ return x.m < y.m; });
    }

    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= i; j--) {
        }
        f[i - 1] = 0;
    }

    for (int i = 1; i <= T; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
