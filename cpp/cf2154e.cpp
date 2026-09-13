#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e5 + 25;
int n;
ll m, a[kn], s[kn];

inline ll chk(int i, int md){
    if(md < 0) return s[n];
    int j = min(i - 1ll, md * m);
    return s[n] + (a[i] * j - s[j]) + (a[i] * md - s[i+md] + s[i]);
}

inline void _solv(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i=1; i<=n; ++i){
        s[i] = s[i-1] + a[i];
    }

    ll ans = 0;
    for(int i=1; i<=n; ++i){
        int lt = 0, rt = min(n - i, i - 1), at = 0;
        while(lt <= rt){
            int md = (lt+rt)>>1;
            if(chk(i, md) - chk(i, md - 1) >= 0) lt = md + 1, at = md;
            else rt = md - 1;
        }
        ans = max(ans, chk(i, at));
    }
    printf("%lld\n", ans);
}
signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) _solv();
    return 0;
}