#include <bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll = long long;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int kn = 2e5 + 25, mod = 998244353;
int n;
ll a[kn], jc[kn];
inline ll fpow(ll x, int y) {
  int res = 1;
  while (y) {
    if (y & 1)
      res = res * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return res;
}

inline void _solv() {
  cin >> n;
  jc[0] = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    jc[i] = jc[i - 1] * i % mod;
  }
  sort(a + 1, a + n + 1, [](ll x, ll y) { return x > y; });

  ll ans = 0, sum = 0;
  for (int i = 1; i <= n; ++i) {
    ll val = (sum - (i - 1) * a[i] % mod + mod) % mod;
    ll num = jc[n - 1] * fpow(i - 1, mod - 2) % mod;
    ans = (ans + val * num % mod) % mod;
    // printf("%d: %lld %lld\n", i, val, num);
    sum = (sum + a[i]) % mod;
  }
  printf("%lld\n", ans);
  // printf("\n\n");
}
signed main() {
  cin.tie(0)->ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--)
    _solv();
  return 0;
}
