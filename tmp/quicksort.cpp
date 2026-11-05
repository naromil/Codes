#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int kn = 2e5 + 25;
int n, a[kn];

inline int partition(int l, int r) {
  int j = l;
  for (int i = l; i <= r - 1; i++) {
    if (a[i] < a[r])
      swap(a[i], a[j++]);
  }
  swap(a[j], a[r]);
  return j;
}
void quicksort(int l, int r) {
  if (l >= r)
    return;
  int pivot = partition(l, r);
  quicksort(l, pivot - 1);
  quicksort(pivot + 1, r);
}

inline int calc(int l, int r) { return rand() % (r - l + 1) + l; }
signed main() {
  cin.tie(0)->ios::sync_with_stdio(false);
  srand(time(0));
  n = calc(20, 30);
  for (int i = 1; i <= n; i++) {
    a[i] = calc(1, 100);
  }

  quicksort(1, n);

  for (int i = 1; i <= n; i++) {
    printf("%d ", a[i]);
  }
  return 0;
}
