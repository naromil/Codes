#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 5e5 + 55, mod = 1e9 + 7;
int n;
string a;
ll f[kn];

int pr[kn], pw[kn], pb[kn];
signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> a;
    a = " " + a;
    for(int i=1; i<=n; ++i){
        pr[i] = (a[i] == 'R' ? i : pr[i-1]);
        pw[i] = (a[i] == 'X' ? i : pw[i-1]);
        pb[i] = (a[i] == 'B' ? i : pb[i-1]);
    }

    f[0] = 1;
    for(int i=1; i<=n; ++i){
        int j = max(pr[i], pb[i]);
        
    }

    printf("%lld\n", (f[n] % mod + mod) % mod);
    return 0;
}