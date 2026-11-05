#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int kn = 2e5 + 25;
int n, a[kn];

void mergesort(int l, int r) {
  if (l >= r)
    return;
  int mid = (l + r) / 2;
  mergesort(l, mid);
  mergesort(mid + 1, r);
  vector<int> tmp;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (a[i] < a[j]) {
      tmp.push_back(a[i++]);
    } else {
      tmp.push_back(a[j++]);
    }
  }
  while (i <= mid) {
    tmp.push_back(a[i++]);
  }
  while (j <= r) {
    tmp.push_back(a[j++]);
  }
  for (int k = l; k <= r; k++) {
    a[k] = tmp[k - l];
  }
}

// random number between l and r
inline int calc(int l, int r) {
  return rand() % (r - l + 1) + l;
}

signed main() {
  cin.tie(0)->ios::sync_with_stdio(false);
  srand(time(0));
  n = calc(20, 30);
  for (int i = 1; i <= n; i++) {
    a[i] = calc(1, 100);
  }

  mergesort(1, n);

  for (int i = 1; i <= n; i++) {
    printf("%d ", a[i]);
  }
  return 0;
}
