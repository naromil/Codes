#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e5 + 25;
multiset<pair<ll, int>> ms;
inline void ms_del(ll x, int i){
    auto it = ms.find(make_pair(x, i));
    if(it != ms.end()) ms.erase(it);
}
int n, m;
ll a[kn];
class Edge{
    public: int x, y; ll w;
    bool operator < (const Edge &nx) const {
        return w < nx.w;
    }
}e[kn];

int fu[kn], mini[kn];
inline int find(int x){ return fu[x] == x ? x : fu[x] = find(fu[x]); }
inline void _union(int x, int y){
    int fx = find(x), fy = find(y);
    fu[fy] = fx;
    if(a[mini[fx]] <= a[mini[fy]]){
        ms_del(a[mini[fy]], mini[fy]);
    }
    else{
        ms_del(a[mini[fx]], mini[fx]);
        mini[fx] = mini[fy];
    }
}

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        fu[i] = mini[i] = i;
        ms.insert(make_pair(a[i], i));
    }
    for(int i=1; i<=m; ++i) cin >> e[i].x >> e[i].y >> e[i].w;
    sort(e + 1, e + m + 1);
    ll ans = 0;
    for(int i=1,j=1; i<n; ++i){
        auto it = ms.begin();
        int x = (*it).second, y = (*++it).second;
        while(j <= m && find(e[j].x) == find(e[j].y)) ++j;
        if(j <= m && e[j].w < a[x] + a[y]){
            _union(e[j].x, e[j].y);
            ans += e[j++].w;
        }
        else{
            _union(x, y);
            ans += a[x] + a[y];
        }
    }
    printf("%lld\n", ans);
    return 0;
}
