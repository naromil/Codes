#include<bits/stdc++.h>
#define emp emplace_back
#define pii pair<int,int>
#define x first
#define y second
#define mkp make_pair
using namespace std;
using ll=long long;
const int kn = 5e3 + 53;
int n, d, lmc[kn], rmc[kn], mpt = 0, vis[kn];
pii a[kn];
vector<int> c[kn];
unordered_map<string, int> mp;
int hungary(int u, int b){
    for(auto v: c[u]){
        if(vis[v] == b) continue;
        vis[v] = b;
        if(!rmc[v] || hungary(rmc[v], b)){
            rmc[v] = u;
            lmc[u] = v;
            return 1;
        }
    }
    return 0;
}
bool lvis[kn], rvis[kn];
void dfs(int u){
    lvis[u] = true;
    for(auto v: c[u]){
        if(rvis[v]) continue;
        rvis[v] = true;
        dfs(rmc[v]);
    }
}
vector<int> lans[kn], rans[kn];
signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> d;
    for(int i=1; i<=n; ++i){
        string str, s1 = "", s2 = "";
        cin >> str;
        for(int j=0; j<d; ++j){
            s1 = s1 + str[j];
            s2 = str[str.size()-1-j] + s2;
        }
        if(!mp.count(s1)) mp[s1] = ++mpt;
        if(!mp.count(s2)) mp[s2] = ++mpt;
        a[i] = mkp(mp[s1], mp[s2]);
        c[mp[s1]].emp(mp[s2]);
    }

    int mxmc = 0;
    for(int i=1; i<=mpt; ++i){
        mxmc += hungary(i, i);
    }
    printf("%d\n", mxmc); // ++
    for(int i=1; i<=mpt; ++i){
        if(!lmc[i]) dfs(i);
    }
    for(int i=1; i<=n; ++i){
        if(!lvis[a[i].x]) lans[a[i].x].emp(i); // lvis[...] -> !lvis[...]
        else rans[a[i].y].emp(i);
    }
    for(int i=1; i<=mpt; ++i){
        if(!lans[i].empty()){
            printf("%ld ", lans[i].size());
            for(auto cr: lans[i]) printf("%d ", cr);
            printf("\n");
        }
        if(!rans[i].empty()){
            printf("%ld ", rans[i].size());
            for(auto cr: rans[i]) printf("%d ", cr);
            printf("\n");
        }
    }
    return 0;
}