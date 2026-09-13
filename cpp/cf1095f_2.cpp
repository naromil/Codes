#include<bits/stdc++.h>
#define emp emplace_back
#define mkp make_pair
using namespace std;
using ll=long long;
const int kn = 2e5 + 25;
int n, m, fu[kn], mini[kn];
ll a[kn];
multiset<pair<ll, int>> ms;
inline void ms_del(int i){
    auto it = ms.find(mkp(a[i], i));
    if(it != ms.end()) ms.erase(it);
}
int find(int x){ return (fu[x] == x) ? x : fu[x] = find(fu[x]); }
inline void unionn(int x, int y){
    int fx = find(x), fy = find(y);
    fu[fy] = fx;
    if(a[mini[fx]] <= a[mini[fy]]) ms_del(mini[fy]);
    else ms_del(mini[fx]), mini[fx] = mini[fy];
}
class Node{
    public: int x, y; ll w;
    bool operator < (const Node &nx) const { return w < nx.w; }
}e[kn];

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        fu[i] = i;
        mini[i] = i;
        ms.insert(mkp(a[i], i));
    }
    for(int i=1; i<=m; ++i){
        cin >> e[i].x >> e[i].y >> e[i].w;
    }
    sort(e + 1, e + m + 1);

    ll ans = 0;
    for(int i=1,j=1; i<n; ++i){
        auto it = ms.begin();
        int x = (*it).second, y = (*++it).second;
        while(j <= m && find(e[j].x) == find(e[j].y)) ++j;
        if(j <= m && e[j].w < a[x] + a[y]){
            unionn(e[j].x, e[j].y);
            ans += e[j].w;
        }
        else{
            unionn(x, y);
            ans += a[x] + a[y];
        }
    }
    printf("%lld\n", ans);
    return 0;
}
    