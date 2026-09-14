#include <bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll = long long;
const int kn = 2e5 + 25, inf = 0x3f3f3f3f;
int n, a[kn], A = inf, B = inf, C = inf;
class Answer {
public:
  ll val;
  int A, B, C;
} ans;

inline ll calc() {
  ll val = 0;
  int bs1 = (B - A + 1) & 1;
  int bs2 = (C - B + 1) & 1;
  int bs3 = (bs1 & bs2) ^ 1;
  for (int i = 1; i <= n; ++i) {
    if (i < A)
      continue;
    else if (i < B)
      val += A;
    else if (i < C)
      val += (B - A) + bs1 * A;
    else
      val += (C - B) + bs2 * (B - A) + bs3 * A;
  }
  return val;
}

void dfs(int u, int cnt) {
  if (cnt > 3)
    return;
  if (u > n) {
    A = B = C = inf;
    for (int i = 1; i <= n; ++i) {
      if (a[i] == 1) {
        if (A > n)
          A = i;
        else if (B > n)
          B = i;
        else
          C = i;
      }
    }
    if (cnt > 3)
      return;
    ll val = calc();
    if (val > ans.val) {
      ans = {val, A, B, C};
    }
    return;
  }
  a[u] = 0;
  dfs(u + 1, cnt);
  a[u] = 1;
  dfs(u + 1, cnt + 1);
}

inline void _solv() {
  cin >> n;
  ans = {0, 0, 0, 0};
  if (n <= 12) {
    dfs(1, 0);
  } else {
    int anchorA = n / 3, anchorB = n * 2 / 3;
    for (int i = -2; i <= 2; ++i) {
      for (int j = -2; j <= 2; ++j) {
        for (int k = 0; k <= 1; ++k) {
          A = anchorA + i;
          B = anchorB + j;
          C = k ? n : inf;
          ll val = calc();
          if (val > ans.val) {
            ans = {val, A, B, C};
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    printf((i == ans.A || i == ans.B || i == ans.C) ? "1" : "0");
  }
  printf("\n");
}
inline void tst() {
  string s;
  while (true) {
    cin >> s;
    n = s.size();
    A = B = C = inf;
    for (int i = 1; i <= n; ++i) {
      a[i] = s[i - 1] - '0';
      if (a[i] == 1) {
        if (A > n)
          A = i;
        else if (B > n)
          B = i;
        else
          C = i;
      }
    }
    ll val = calc();
    printf("%lld", val);
    cout << endl;
  }
  exit(0);
}
signed main() {
  //  tst();
  cin.tie(0)->ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--)
    _solv();
  return 0;
}
