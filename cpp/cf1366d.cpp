#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 5e5 + 55, lim = 1e7;
int n, a[kn];
int cur[lim+17], sm[lim+17], tms[lim+17], nxt[lim+17];
bool vis[lim+17];
vector<int> pr;
inline void seive(){
    vis[1] = true;
    for(int i=2; i<=lim; ++i){
        if(!vis[i]) pr.emp(i);
        for(auto cr: pr){
            if(1ll*i*cr > lim) break;
            vis[i * cr] = true;
            if(i % cr == 0) break;
        }
    }
    for(int i=0; i+1<pr.size(); ++i) nxt[pr[i]] = pr[i+1];
}
int ans1[kn], ans2[kn];
signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n;
    seive();
    cur[1] = 2; sm[1] = 0; tms[1] = 1;
    for(int i=1; i<=lim; ++i){
        for(int cr=cur[i]; cr; cr=nxt[cr]){
            if(1ll*i*cr > lim) break;
            cur[i*cr] = cr;
            sm[i*cr] = (i==1) ? cr : sm[i];
            tms[i*cr] = (cr==sm[i*cr]) ? tms[i] * cr : tms[i];
        }
    }
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        if(!vis[a[i]] || a[i] == tms[a[i]]) ans1[i] = ans2[i] = -1;
        else{ ans1[i] = sm[a[i]]; ans2[i] = a[i] / tms[a[i]]; }
    }
    for(int i=1; i<=n; ++i) printf("%d ", ans1[i]);
    printf("\n");
    for(int i=1; i<=n; ++i) printf("%d ", ans2[i]);
    printf("\n");
    return 0;
}