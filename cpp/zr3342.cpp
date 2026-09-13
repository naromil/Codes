#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn = 6666;
const ll inf = 0x3f3f3f3f3f3f3f3f; // int -> ll
int n;
class Node{
    public: ll x, y; int i;
    bool operator < (const Node &v) const {
        return (y != v.y) ? y < v.y : x > v.x;
    }
}a[kn];

ll f[kn][kn], dp[kn];
inline void _solv(){
    cin >> n;
    for(int i=0; i<=n+5; ++i){
        dp[i] = -inf; // 0 -> -inf
        for(int j=0; j<=n+5; ++j){
            f[i][j] = -inf; // 0 -> -inf
        }
    }
    for(int i=1; i<=n; ++i){
        cin >> a[i].x >> a[i].y;
        a[i].i = i;
    }
    sort(a + 1, a + n + 1);
    int mxl = 0, m = 0;
    for(int i=1; i<=n; ++i){
        if(mxl >= a[i].x){
            dp[i-m] = a[i].y - a[i].x + 1;
        }
        else{
            mxl = a[i].x;
            a[++m] = a[i];
        }
    }

    dp[0] = 0;
    sort(dp + 1, dp + n - m + 1, [](ll x, ll y){ return x > y; });
    for(int i=1; i<=n-m; ++i) dp[i] += dp[i-1];
//    for(int i=0; i<=n-m; ++i) printf("%lld ", dp[i]);
//    printf("\n");
    deque<int> q;
    f[0][0] = 0;
    for(int k=1; k<=m; ++k){
        for(int i=k; i<=m; ++i){
            while(!q.empty() && f[q.back()][k-1] + a[q.back()+1].y < f[i-1][k-1] + a[i].y) q.pop_back(); // q.front() -> q.back()
            q.push_back(i-1);
            while(!q.empty() && a[q.front()+1].y < a[i].x) q.pop_front();
            if(!q.empty()) f[i][k] = f[q.front()][k-1] + (a[q.front()+1].y - a[i].x + 1);
//            printf("%d %d: %lld\n", i, k, f[i][k]);
        }
        while(!q.empty()) q.pop_back();
    }
    
    for(int i=1; i<=n; ++i){
        ll ans = -inf;
        for(int j=0; j<=m&&j<=i; ++j) ans = max(ans, f[m][j] + dp[i-j]); // f[m][j] -> f[j][m]
        printf("%lld ", (ans <= 0) ? -1 : ans);
    }
    printf("\n"); // ++
}

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    int T; cin >> T >> T;
    while(T--) _solv();
    return 0;
}