#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 1e4 + 14, mod = 1e9 + 7;
ll f[2][kn], n, nxt[kn];
inline void get_nxt(const string &s){
    int i = 2, j = 1;
    nxt[1] = 0;
    while(i < s.size()){
        if(s[i] == s[j]) nxt[i++] = j++;
        else if(j > 1) j = nxt[j-1] + 1;
        else nxt[i++] = 0; // j++ -> i++
    }
}
inline void chk(const string &s, const string &b, int k){
    int i = 1, j = 1;
    while(i < s.size()){
        if(s[i] == b[j]) ++i, ++j;
        else if(j > 1) j = nxt[j-1] + 1;
        else ++i;
        if(j == b.size()){
            f[k][i-1] = (f[k][i-1] + f[k^1][i-b.size()]) % mod;
            j = nxt[j-1] + 1;
        }
    }
}
signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    string s;
    cin >> n >> s;
    s = " " + s;
    for(int i=0; i<s.size(); ++i) f[0][i] = 1;
    for(int i=1; i<=n; ++i){
        int x = i & 1;
        memset(f[x], 0, sizeof f[x]);
        int m; cin >> m;
        for(int j=1; j<=m; ++j){
            string b; cin >> b; b = " " + b;
            get_nxt(b);
            chk(s, b, x);
        }
//        printf("%d: ", i);
//        for(int j=1; j<s.size(); ++j) printf("%lld ", f[x][j]);
//        printf("\n");
    }
    ll ans = 0;
    for(int i=n; i<s.size(); ++i){
        ans = (ans + f[n&1][i]) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}