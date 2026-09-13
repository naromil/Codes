#include<bits/stdc++.h>
#define FILE(x) freopen(#x".in","r",stdin), freopen(#x".out","w",stdout)
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 5015, mod = 998244353;
int n, a[kn], tt0, tt1, tt2, tt3, mc1[kn], mc3[kn];
ll f[kn][kn];

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        if(a[i] == 0) ++tt0;
        else if(a[i] == 1) ++tt1;
        else if(a[i] == 2) ++tt2;
        else ++tt3;
    }
    for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j){
        if((a[i] == 2 && a[j] == 0) || (a[i] == 3 && a[j] == 1)){
            printf("0\n");
            return 0;
        }
    }

    int c0 = 0, c1 = 0, c2 = 0, c3 = 0;
    for(int i=1; i<=n; ++i){
        if(a[i] == 0 || a[i] == 3) continue;
        else if(a[i] == 2) ++c2;
        else ++c1, mc1[tt0+c1] = c2;
    }
    for(int i=n; i>=1; --i){
        if(a[i] == 1 || a[i] == 2) continue;
        else if(a[i] == 0) ++c0;
        else ++c3, mc3[tt2+c3] = c0;
    }

    f[0][0] = 1;
    for(int i=0; i<=tt0+tt1; ++i) for(int j=0; j<=tt2+tt3; ++j){
        if(i + 1 <= tt0 + tt1 && mc1[i+1] <= j) f[i+1][j] = (f[i+1][j] + f[i][j]) % mod;
        if(j + 1 <= tt2 + tt3 && mc3[j+1] <= i) f[i][j+1] = (f[i][j+1] + f[i][j]) % mod;
    }
    printf("%lld\n", f[tt0+tt1][tt2+tt3]);
    return 0;
}