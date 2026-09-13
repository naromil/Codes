#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e5 + 25;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int n, mc[kn], lx[kn], rx[kn];
ll a[kn], b[kn];

inline ll calc(int i, int j){
    if(i > j) swap(i, j);
    if(i == 0 || j == n + 1)
        return inf;
    else if((i & 1) && !(j & 1))
        return ((a[j] - a[i] - 1) / (b[i] + b[j]) + 1) * 2 - 1;
    else if(!(i & 1) && (j & 1))
        return ((a[j] - a[i] - 1) / (b[i] + b[j]) + 1) * 2;
    return inf;
}
class Node{
    public: ll w; int i, j;
    bool operator < (const Node &nx) const { return w > nx.w; }
};

inline void _solv(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    priority_queue<Node> pq;
    for(int i=1; i<=n; ++i){
        cin >> b[i];
        lx[i] = i - 1;
        rx[i] = i + 1;
        mc[i] = 0;
        if(i > 1) pq.push({calc(i - 1, i), i - 1, i});
    }
    for(int cs=1; cs<=(n>>1); ++cs){
        while(mc[pq.top().i] || mc[pq.top().j]) pq.pop();
        int x = pq.top().i, y = pq.top().j;
        mc[x] = y;
        mc[y] = x;
        rx[lx[x]] = rx[y];
        lx[rx[y]] = lx[x];
        pq.push({calc(lx[x], rx[y]), lx[x], rx[y]});
    }

    for(int i=1; i<=n; ++i){
        printf("%lld ", calc(mc[i], i));
    }
    printf("\n");
}
signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) _solv();
    return 0;
}