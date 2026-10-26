#include <bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll = long long;
const int kn = 2e5 + 25;

int n;
string s0, s1;

inline void _solv() {
    cin >> n >> s0 >> s1;
    s0 = " " + s0;
    s1 = " " + s1;

    int n0 = 0, c0 = 0, n1 = 0, c1 = 0;
    bool flg = false;
    for (int i = 1; i <= n; ++i) {
        if (s0[i] == 'f') {
            ++n0;
            if (flg == true) {
                flg = false;
                ++c0;
            }
            else flg = true;
        }
        else flg = false;
    }
    flg = false;
    for (int i = 1; i <= n; ++i) {
        if (s1[i] == 'f') {
            ++n1;
            if (flg == true) {
                flg = false;
                ++c1;
            }
            else flg = true;
        }
        else flg = false;
    }

    while (n0 > n1 && c0 > 0) {
        n0 -= 2;
        --c0;
    }
    while (n1 > n0 && c1 > 0) {
        n1 -= 2;
        --c1;
    }

    printf("%d\n", abs(n0 - n1));
}

signed main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) _solv();
    return 0;
}
