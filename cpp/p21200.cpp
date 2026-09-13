#include<bits/stdc++.h>
#define qsz q.size()
using namespace std;
using ll=long long;
const int kn = 1e6 + 16;
int n, X[kn], P[kn], C[kn];
ll dis[kn], num[kn], f[kn];
inline ll rup(int j, int k){ return (f[j] + dis[j]) - (f[k] + dis[k]); }
inline ll rdn(int j, int k){ return num[j] - num[k]; }
inline ll calc(int j, int i){ return X[i] * (num[i] - num[j]) - (dis[i] - dis[j]); }
signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> X[i] >> P[i] >> C[i];
        dis[i] = dis[i-1] + 1ll * X[i] * P[i];
        num[i] = num[i-1] + P[i];
    }

    memset(f, 0x3f, sizeof f); // forgot
    f[0] = 0;
    deque<int> q; q.push_back(0);
    for(int i=1; i<=n; ++i){
        while(qsz >= 2 && rup(q[0],q[1]) >= X[i] * rdn(q[0],q[1])) q.pop_front();
        if(qsz) f[i] = f[q[0]] + calc(q[0], i) + C[i];
        while(qsz >= 2 && rup(q[qsz-2],q[qsz-1]) * rdn(q[qsz-1],i) >= rup(q[qsz-1],i) * rdn(q[qsz-2],q[qsz-1])) q.pop_back();
        q.push_back(i);
    }
    ll ans = 0x3f3f3f3f3f3f3f3f;
    for(int i=n; i>=1; --i){
        ans = min(ans, f[i]);
        if(P[i]) break;
    }
    printf("%lld\n", ans);
    return 0;
}
/*
f[i] = f[j] + calc(j, i) + C[i]
f[i] = f[j] + X[i] * (num[i] - num[j]) - (dis[i] - dis[j]) + C[i]
f[i] = (f[j] - X[i]*num[j] + dis[j]) - dis[i] + X[i]*num[i] + C[i]
f[i] = (W[j] - X[i]*num[j]) - dis[i] + X[i]*num[i] + C[i]

j < k
W[j] - X[i]*num[j] < W[k] - X[i]*num[k]
W[j] - W[k] < X[i] * (num[j] - num[k])
(W[j] - W[k]) / (num[j] - num[k]) < X[i]
*/