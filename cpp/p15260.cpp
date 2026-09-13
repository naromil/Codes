#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e5 + 25;
int n;
ll m;
vector<ll> a, b;

inline void _solv(){
    cin >> n >> m;
    a.resize(n);
    b.resize(n);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    auto chk = [&](ll md) -> bool {
        vector<ll> na = a, nb = b;
        ll W = m;
        for(int i=0; i<n; ++i){
            if(na[i] - nb[i] > md){
                ll w = (na[i] - nb[i] - md + 1) >> 1;
                if(w > W) return false;
                na[i] -= w;
                nb[i] += w;
                W -= w;
            }
        }
        if(W < 0) return false;
        ll lt = *min_element(nb.begin(), nb.end()), rt = lt + md, at = lt;
        ll sum = 0;
        vector<ll> vec;
        ll cnt = 0;
        for(int i=0; i<n; ++i){
            vec.emp(nb[i]);
            if(na[i] > rt){
                sum += na[i] - rt;
                --cnt;
                vec.emp(na[i] - md);
            }
        }
        if(sum <= W) return true;
        sort(vec.begin(), vec.end());
        for(int i=0; i<vec.size()&&cnt<0; ++i){
            auto cr = vec[i];
            sum += (cr - at) * cnt;
            if(sum <= W) return true;
            ++cnt;
            at = cr;
        }
        return false;
    };
    ll lt = -3e18, rt = 3e18;
    while(lt < rt){
        ll md = (lt+rt)>>1;
        if(chk(md)) rt = md;
        else lt = md + 1;
    }
    printf("%lld\n", lt);
}
signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) _solv();
    return 0;
}