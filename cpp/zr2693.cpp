#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e5 + 25;
int n, a[kn], q;
int st[kn][20];
inline void st_init(){
    for(int i=1; i<=n; ++i){
        st[i][0] = -a[i] + i;
    }
    for(int k=1; k<20; ++k){
        for(int i=1; i+(1<<k-1)<=n; ++i){
            st[i][k] = max(st[i][k-1], st[i+(1<<k-1)][k-1]);
        }
    }
}
inline int calc(int l, int r){
    int len = log2(r - l + 1);
    return max(st[l][len], st[r-(1<<len)+1][len]);
}

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
    }
    st_init();
    cin >> q;
    for(int i=1; i<=q; ++i){
        int x, y; cin >> x >> y;
        int ps = lower_bound(a + 1, a + n + 1, a[y]) - a;
        int ans = ((a[x] == a[y]) ? 0 : a[y] + calc(x, ps) - x);
        printf("%d\n", ans);
    }
    return 0;
}