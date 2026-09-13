#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;
const int C = 26;
int main() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    if (s == t) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> to(C, -1);
    for (int i = 0; i < n; i++) {
        int sc = s[i] - 'a';
        int tc = t[i] - 'a';
        if (to[sc] != -1 and to[sc] != tc) {
            cout << -1 << endl;
            return 0;
        }
        to[sc] = tc;
    }
    bool is_perm = true;
    vector<int> tmp = to;
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < C; i++) {
        is_perm &= (tmp[i] == i);
    }
    if (is_perm) {
        cout << -1 << endl;
        return 0;
    }
    int ans = 0;
    vector<int> in_deg(C);
    dsu uf(C);
    for (int i = 0; i < C; i++) {
        if (to[i] != -1) {
            if (to[i] != i) {
                ans++;
            }
            in_deg[to[i]]++;
            uf.merge(i, to[i]);
        }
    }
    vector<vector<int>> groups = uf.groups();
    for (const vector<int> &g: groups) {
        bool is_cycle = true;
        for (int i: g) {
            is_cycle &= (in_deg[i] == 1);
        }
        if (is_cycle and g.size() > 1) {
            ans++;
        }
    }
    cout << ans << endl;
}
