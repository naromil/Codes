#include<bits/stdc++.h>
#define emp emplace_back
#define pll pair<ll,ll>
#define x first
#define y second
#define mkp make_pair
using namespace std;
using ll=long long;
const int kn = 515, mod = 1e9 + 7;
int n, a[kn], b[kn];
ll f[kn][kn], as[kn], bs[kn], s[kn][kn];
vector<int> av[kn], bv[kn];
bool operator < (pll A, pll B){ return A.x * B.y < B.x * A.y; }
inline pll ca(int x, int y){ return mkp(as[y] - as[x], 1ll * (y - x)); }
inline pll cb(int x, int y){ return mkp(bs[y] - bs[x], 1ll * (y - x)); }

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        as[i] = as[i-1] + a[i];
    }
    for(int i=1; i<=n; ++i){
        cin >> b[i];
        bs[i] = bs[i-1] + b[i];
    }

    for(int i=1; i<=n; ++i){
        for(int j=0; j<i; ++j){
            av[i].emp(j);
            bv[i].emp(j);
        }
        sort(av[i].begin(), av[i].end(), [i](int x, int y){ return ca(y, i) < ca(x, i); });
        sort(bv[i].begin(), bv[i].end(), [i](int x, int y){ return cb(y, i) < cb(x, i); });
    }

    f[0][0] = 1;
    for(int j=1; j<=n; ++j){
        for(int i=0; i<=n; ++i){
            if(i){
                for(int ii=0,jj=0; ii<av[i].size(); ++ii){
                    while(jj < bv[j].size() && (cb(bv[j][jj], j) < ca(av[i][ii], i)) == false)
                        ++jj;
                    if(jj) f[i][j] = (f[i][j] + s[av[i][ii]][jj-1]) % mod;
                }
            }
            for(int jj=0; jj<bv[j].size(); ++jj)
                s[i][jj] = ((jj ? s[i][jj-1] : 0) + f[i][bv[j][jj]]) % mod;
        }
        memset(s, 0, sizeof s);
    }
    printf("%lld\n", f[n][n]);
    return 0;
}