#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn=5e5 + 55;
int n;
ll m;
struct Node{ ll v, w; }a[kn];
bool cmp(Node X, Node Y){ return (X.w == Y.w) ? X.v > Y.v : X.w < Y.w; }
signed main(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i){ cin >> a[i].v >> a[i].w; }
    a[++n] = {0, m + 1};
    sort(a + 1, a + n + 1, cmp);

    vector<Node> v;
    ll cw = a[1].w, ans = 0;
    for(int i=1; i<=n; ++i){
        if(a[i].w == cw){ v.emp(a[i]); }
        else{
            m -= m % cw;
            sort(v.begin(), v.end(), cmp);
            vector<Node> vec;
            ll crw = 0, crv = 0;
            for(int j=0; j<v.size(); ++j){
                if(m % a[i].w > 0){ m -= v[j].w; ans += v[j].v; }
                else{
                    crw += v[j].w;
                    crv += v[j].v;
                    if(crw == a[i].w){ vec.emp(Node{crv, crw}); crw = crv = 0; }
                }
            }
            if(crw > 0) vec.emp(Node{crv, a[i].w});
            v = vec;
            v.emp(a[i]);
            cw = a[i].w;
        }
    }
    printf("%lld\n", ans);
    return 0;
}