#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e5 + 25;
int n=0, m=0, t[kn][26], q, id[kn], fa[kn], fail[kn];
inline void insert(const string &str){
    int u = 0;
    for(int i=0; i<str.size(); ++i){
        if(str[i] == 'B'){ u = fa[u]; }
        else if(str[i] == 'P'){ id[++m] = u; }
        else{
            int j = str[i] - 'a';
            if(!t[u][j]){ t[u][j] = ++n; fa[t[u][j]] = u; }
            u = t[u][j];
        }
    }
}
inline void get_fail(){
    queue<int> q;
    for(int j=0; j<26; ++j){
        if(t[0][j]) q.push(t[0][j]);
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int j=0; j<26; ++j){
            if(!t[u][j]) t[u][j] = t[fail[u]][j];
            else{ fail[t[u][j]] = t[fail[u]][j]; q.push(t[u][j]); } // added " q.push(t[u][j]); "
        }
    }
}
int siz[kn], dfn[kn], dft=0, ans[kn];
vector<int> c[kn];
vector<pair<int,int>> qs[kn];
void dfs(int u){
    dfn[u] = ++dft;
    siz[u] = 1;
    for(auto v: c[u]){
        dfs(v);
        siz[u] += siz[v];
    }
}
int ts[kn];
inline int lb(int x){ return -x & x; }
inline void upd(int x, int w){ for(; x<=n; x+=lb(x)) ts[x] += w; } // modified "x<=n"
inline int qry(int x){ int res = 0; for(; x; x-=lb(x)){ res += ts[x]; } return res; }
void dfs2(int u){
    upd(dfn[u], 1);
    for(int j=0; j<26; ++j){
        if(!t[u][j] || fa[t[u][j]] != u) continue; // added "!t[u][j] || "
        dfs2(t[u][j]);
    }
    for(auto cr: qs[u]){
        int b = cr.first;
        ans[cr.second] += qry(dfn[b] + siz[b] - 1) - qry(dfn[b] - 1);
    }
    upd(dfn[u], -1);
}
signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    string str; cin >> str;
    insert(str);
    get_fail();
    for(int i=1; i<=n; ++i){
        c[fail[i]].emp(i);
    }
    dfs(0);

    cin >> q;
    for(int i=1; i<=q; ++i){
        int x, y; cin >> x >> y;
        qs[id[y]].emp(make_pair(id[x], i));
    }
    dfs2(0);
    for(int i=1; i<=q; ++i){
        printf("%d\n", ans[i]);
    }
    return 0;
}