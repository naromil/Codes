#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int kn = 2e5 + 25;
int n;
ll a[kn], b[kn];

ll mp[4000025];
ll maxi = 0;

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);

    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
    }

    ll sum = 0;
    for(int i=1; i<=n; ++i){
        cin >> b[i];
        sum += b[i];
    }

    ll ans = 0x3f3f3f3f3f3f3f3f;
    for(int k=0; k<=1e6; ++k){

        maxi = 0;
        for(int i=1; i<=n; ++i){
            int val = (i - 1) * k;
            if(val > 1e6) break;

            mp[a[i] - val + 2000000] += b[i];
            maxi = max(maxi, mp[a[i] - val + 2000000]);
        }
        
        ans = min(ans, sum - maxi);

        for(int i=1; i<=n; ++i){
            int val = (i - 1) * k;
            if(val > 1e6) break;
            mp[a[i] - val + 2000000] = 0;
        }
    }

    printf("%lld\n", ans);
    return 0;
}