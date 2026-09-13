#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 5e5 + 55, inf = 0x3f3f3f3f;
int n, m, a[kn], tt = 0, in[kn];
vector<int> c[kn], cc[kn];

inline void toposort(){
    queue<int> q;
    for(int i=1; i<=n; ++i){
        if(!in[i]) q.push(i);
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        a[++tt] = u;
        for(auto v: c[u]){
            if(!--in[v]) q.push(v);
        }
    }
}

int dl[kn], dr[kn]; // starting from i, ending with i
multiset<int> st;
inline void del(int x){
    auto it = st.find(x);
    if(it != st.end()) st.erase(it);
}

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1; i<=m; ++i){
        int x, y; cin >> x >> y;
        c[x].emp(y);
        cc[y].emp(x);
        ++in[y];
    }
    toposort();

    for(int i=1; i<=n; ++i){
        int u = a[i];
        for(auto v: c[u]) dr[v] = max(dr[v], dr[u] + 1);
    }
    for(int i=n; i>=1; --i){
        int u = a[i];
        for(auto v: c[u]) dl[u] = max(dl[u], dl[v] + 1);
        st.insert(dl[u]);
    }

    int ans = inf, ps = 1;
    for(int i=1; i<=n; ++i){
        int u = a[i];
        del(dl[u]);
        for(auto v: cc[u]) del(dr[v] + 1 + dl[u]);
        int res = *st.rbegin();
        if(res < ans) ans = res, ps = u;
        st.insert(dr[u]);
        for(auto v: c[u]) st.insert(dr[u] + 1 +  dl[v]);
    }
    printf("%d %d\n", ps, ans);
    return 0;
}