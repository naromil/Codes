#include <bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll = long long;

int n, m;

inline void _solv() {
    cin >> n;
    if (n == -1) exit(0);
    string s = "++";
    for (int i = 1; i <= n + 2; i++) {
        s += "--+";
    }
    cout << s << '\n';
    cout.flush();

    cin >> m;
    int num2 = (m - 2) / 3;
    cout << num2 + n << '\n';
    cout.flush();
}
signed main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) _solv();
    return 0;
}
