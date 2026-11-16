#include <bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll = long long;
const int kn = 3e5 + 35;

int n;

inline void _solv() {
    cin >> n;
    if (n <= 3) {
        printf("-1\n");
    }
    else {
        vector<int> a(n);
        iota(a.begin(), a.end(), 1);
        swap(a[0], a[3]);
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}
signed main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) _solv();
    return 0;
}
