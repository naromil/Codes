#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e5 + 25;
int n, a[kn], b[kn];
ll m;

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> m;
    int mn = 0x3f3f3f3f;
    for(int i=1; i<=n; ++i){
        cin >> a[i] >> b[i];
        mn = min(mn, a[i] + b[i]);
    }
    sort(a + 1, a + n + 1);
    ll sum = 0, ans = 0;
    for(int i=0; i<=n; ++i){
        sum += a[i];
        if(sum > m) break;
        ans = max(ans, i + (m - sum) / mn * 2);
    }
    printf("%lld\n", ans);
    return 0;
}
