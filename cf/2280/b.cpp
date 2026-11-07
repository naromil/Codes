#include <bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll = long long;
const int kn = 6e5 + 65;

int n, a[kn];

inline void _solv() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}
signed main() {
    int T; cin >> T;
    while (T--) {
        _solv();
    }
}
