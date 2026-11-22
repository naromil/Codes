#include <bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll = long long;
const int kn = 5e4 + 54, n = 5e4;

struct Quest { int m, i; };
vector<Quest> ls[kn];
int ans[kn];

bitset<kn> mask[kn], f;

signed main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        int x, y; cin >> x >> y;
        ls[x].emp(Quest{y, i});
    }

    bitset<kn> len;
    len[0] = 1;
    for (int i = 1; i <= n; i++) {
        mask[i] |= len;
        len[i] = 1;
        sort(ls[i].begin(), ls[i].end(), [](Quest x, Quest y){ return x.m < y.m; });
    }

    for (int i = 2; i <= n; i++) {
        bitset<kn> bs;
        bs.set();
        for (int j = i; j <= n; j += i) {
            mask[j] &= bs;
            bs[j] = 0;
        }
    }

    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= i; j--) {
            f[j] = ((f & mask[j]).count() & 1);
        }
        f[i - 1] = 0;

        int j = i - 1, sum = 0;
        for (auto cr : ls[i]) {
            while (j < cr.m) sum ^= f[++j];
            ans[cr.i] = sum;
        }
    }

    for (int i = 1; i <= T; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
