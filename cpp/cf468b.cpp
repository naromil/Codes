#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 1e5 + 15;
int n, A, B, a[kn], mc[kn], vis[kn];
unordered_map<int,int> mp;
vector<int> c[kn];

bool op = false, sf[kn];
bool hungary(int u, int b){
    for(auto v: c[u]){
        if(vis[v] == b) continue;
        if(sf[v] && !op) continue;
        vis[v] = b;
        if(!mc[v] || hungary(mc[v], b)){
            mc[v] = u;
            mc[u] = v;
            return true;
        }
    }
    return false;
}

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> A >> B;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        mp[a[i]] = i;
        if(a[i] + a[i] == A || a[i] + a[i] == B) sf[i] = true;
    }
    for(int i=1; i<=n; ++i){
        int lt = mp[A-a[i]], rt = mp[B-a[i]];
        if(lt && lt != i) c[i].emp(lt);
        if(rt && rt != i) c[i].emp(rt);
    }

    int res = 0;
    for(int i=1; i<=n; ++i){
        if(!sf[i] && !mc[i]) res += hungary(i, i);
    }
    op = true;
    for(int i=1; i<=n; ++i){
        if(!mc[i]) res += hungary(i, i);
    }
    res <<= 1;
    for(int i=1; i<=n; ++i){
        if(!mc[i] && ((a[i]<<1) == A || (a[i]<<1) == B)) ++res, mc[i] = i;
    }

    if(res == n){
        printf("YES\n");
        for(int i=1; i<=n; ++i){
            if(a[i] + a[mc[i]] == A) printf("0 ");
            else printf("1 ");
        }
    }
    else printf("NO\n");
    return 0;
}