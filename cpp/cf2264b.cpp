#include <bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll = long long;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int kn = 2e5 + 25;
int n, m, a[kn];

inline void _solv() {
  cin >> n >> m;

  ll ans = -inf, sum = 0;
  multiset<int> ms;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (ms.size() < m - 1) {
      ms.insert(a[i]);
      sum += a[i];
    } else {
      ans = max(ans, 1ll * a[i] * m - sum);
      if (!ms.empty() && a[i] < *ms.rbegin()) {
        sum = sum - *ms.rbegin() + a[i];
        ms.erase(prev(ms.end()));
        ms.insert(a[i]);
      }
    }
  }
  printf("%lld\n", ans);
}
signed main() {
  cin.tie(0)->ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--)
    _solv();
  return 0;
}
