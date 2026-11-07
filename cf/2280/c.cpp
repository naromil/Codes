#include <bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll = long long;
const int kn = 3e5 + 35;

int n, a[kn];

inline bool chk(int mt) {
    vector<int> gap;

    for (int i = 1; i < n; i++) {
        if (abs(a[i] - a[i+1]) > mt) gap.emp(i);
    }

    if (gap.size() >= 3) return false;
    else if (gap.size() == 0) return true;

    else if (gap.size() == 2) {
        int l = gap[0] + 1, r = gap[1];
        for (int i = l; i < r; i++) {
            if (abs(a[i] - a[i+1]) * 2 > mt) return false;
        }
        if (abs(a[l-1] - a[r] * 2) > mt || abs(a[r+1] - a[l] * 2) > mt) return false;
        else return true;
    }

    else if (gap.size() == 1) {
        int x = gap[0];
        for (int i = x; i >= 1; i--) {
            if (abs(a[x+1] - a[i] * 2) <= mt && (i == 1 || abs(a[i-1] - a[x] * 2) <= mt)) return true;
            if (abs(a[i] - a[i-1]) * 2 > mt) break;
        }
        for (int i = x + 1; i <= n; i++) {
            if (abs(a[x] - a[i] * 2) <= mt && (i == n || abs(a[i+1] - a[x+1] * 2) <= mt)) return true;
            if (abs(a[i] - a[i+1]) * 2 > mt) break;
        }
        return false;
    }

    return false;
}

inline void _solv() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int lt = 0, rt = 1e9, at = 1e9;
    while (lt <= rt) {
        int mt = (lt + rt) >> 1;
        if (chk(mt)) {
            rt = mt - 1;
            at = mt;
        }
        else {
            lt = mt + 1;
        }
    }

    printf("%d\n", at);
}
signed main() {
    int T; cin >> T;
    while (T--) {
        _solv();
    }
}
