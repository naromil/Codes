#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 5e5 + 55;
int n, m, A[kn], dis[kn];
bool frm[kn];
vector<int> c[kn];

int N, dep[kn], ans[kn], inrd[kn];
vector<int> rd, del, tp;
void dfs0(int u, int b, int o){
    if(!inrd[u]) inrd[u] = 1;
    dep[u] = dep[b] + 1;
    if(frm[u]){
        del[(o - dep[u] % N + 1 + N) % N] = true;
        dis[u] = -1;
    }

    for(auto v: c[u]){
        if(inrd[v] == 2) continue;
        dfs0(v, u, o);
        dis[u] = min(dis[u], dis[v] + 1);
    }
}
void dfs1(int u, int b, int o){
    int j = (o - dep[u] % N + 1 + N) % N;
    j = (j - dis[u] % N + N) % N;
    int w = dis[u] - (tp[j] - j + N) % N;
    if(dis[u] >= 1e9) ans[u] = -2;
    else ans[u] = (w >= 0) ? w : -1;

    for(auto v: c[u]){
        if(inrd[v] == 2) continue;
        dfs1(v, u, o);
    }
}

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        cin >> A[i];
        c[A[i]].emp(i);
    }
    for(int i=1; i<=m; ++i){
        int x; cin >> x;
        frm[x] = true;
    }
    memset(dis, 0x3f, sizeof dis);

    for(int i=1; i<=n; ++i){
        if(inrd[i]) continue;
        rd.clear();
        int x = i;
        while(inrd[x] != 2){
            if(++inrd[x] == 2) rd.emp(x);
            x = A[x];
        }
        
        N = rd.size();
        del.assign(N, 0);
        tp.assign(N, -1);
        for(int i=0; i<N; ++i) dfs0(rd[i], 0, i);
        for(int i=0; i<(N<<1); ++i) dis[A[rd[i%N]]] = min(dis[A[rd[i%N]]], dis[rd[i%N]] + 1);
        for(int i=(N<<1)-1; i>=0; --i) tp[i%N] = !del[i%N] ? i%N : tp[(i+1)%N];
        for(int i=0; i<N; ++i) dfs1(rd[i], 0, i);
    }

    for(int i=1; i<=n; ++i) printf("%d\n", ans[i]);
    return 0;
}