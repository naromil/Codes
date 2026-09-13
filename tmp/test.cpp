#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int d[100];
void dfs(int k) {
  if (k == 6) {
    vector<bool> vis(10, false);
    bool flg = false;
    for (int i = 1; i <= 5; ++i) {
      if (vis[d[i]]) {
        flg = true;
        break;
      }
      vis[d[i]] = true;
    }
    if (flg == true)
      return;

    int num = d[1] * 1000 + d[2] * 100 + d[3] * 10 + d[4];
    int num2 = d[4] * 1000 + d[3] * 100 + d[2] * 10 + d[1];
    if (num * d[5] == num2)
      printf("%d %d %d %d * %d == %d %d %d %d\n", d[1], d[2], d[3], d[4], d[5],
             d[4], d[3], d[2], d[1]);
    return;
  }
  for (int i = 0; i <= 9; ++i) {
    d[k] = i;
    dfs(k + 1);
  }
}

signed main() {
  cin.tie(0)->ios::sync_with_stdio(false);

  dfs(1);
  return 0;
}
