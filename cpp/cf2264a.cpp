#include <bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll = long long;

const int kn = 2e5 + 25;
int n, a[kn], b[kn];

inline void _solv() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    b[i] = a[i];
  }

  sort(b + 1, b + n + 1);
  vector<int> va, vb;
  for (int i = 1; i <= n; ++i) {
    if (a[i] != b[i])
      va.emp(a[i]), vb.emp(b[i]);
  }
  reverse(va.begin(), va.end());
  printf(va == vb ? "YES\n" : "NO\n");
}
signed main() {
  cin.tie(0)->ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--)
    _solv();
  return 0;
}
