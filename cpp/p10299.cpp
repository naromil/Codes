#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e5 + 25;
int n, f[kn][2];
ll a[2][kn], s[kn][2];
unordered_map<ll, int> mp[2];

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n;
    ll sum = 0;
    for(int k=0; k<=1; ++k){
        for(int i=1; i<=n; ++i){
            cin >> a[k][i];
            sum += a[k][i];
            a[k][i] *= n << 1;
        }
    }
    for(int k=0; k<=1; ++k){
        for(int i=1; i<=n; ++i)
            a[k][i] -= sum, s[i][k] = s[i-1][k] + a[k][i];
    }

    mp[0][0] = mp[1][0] = 0;
    for(int i=1; i<=n; ++i){
        for(int k=0; k<=1; ++k){
            f[i][k] = max(f[i-1][0], f[i-1][1]);
            if(mp[k].count(s[i][k^1]))
                f[i][k] = max(f[i][k], mp[k][s[i][k^1]] + 1);
            if(mp[k^1].count(-s[i][k^1]))
                f[i][k] = max(f[i][k], mp[k^1][-s[i][k^1]] + 1);
        }
        if(s[i][0] + s[i][1] == 0)
            f[i][0] = f[i][1] = max(f[i][0], f[i][1]) + 1;

        mp[0][s[i][1]] = max(mp[0][s[i][1]], f[i][0]);
        mp[1][s[i][0]] = max(mp[1][s[i][0]], f[i][1]);
    }
    printf("%d\n", max(f[n][0], f[n][1]));
    return 0;
}