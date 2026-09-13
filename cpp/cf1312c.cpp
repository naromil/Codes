#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 108;
int n, m, a[kn], cnt[kn];
inline void conv(int x, int y){
    int tt = 0;
    while(x){
        cnt[++tt] += x % m;
        x /= m;
    }
}

inline bool chk(){
    if(m <= 1) return true;
    for(int i=1; i<=n; ++i) conv(a[i], m);
    for(int i=1; i<=64; ++i){
        if(cnt[i] > 1) return false;
    }
    return true;
}

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    int T; cin >> T;
    while(T--){
        cin >> n >> m;
        memset(cnt, 0, sizeof cnt);
        for(int i=1; i<=n; ++i){
            cin >> a[i];
        }
        printf(chk() ? "YES\n" : "NO\n");
    }
    return 0;
}