#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e5 + 25;
int n, b[kn];
ll L, T, a[kn];
ll cnt[kn], ans[kn];
vector<int> v1, v2;

inline ll calc(int i, int j){
    ll w = (a[j] - a[i] + L) % L;
    return (T - w + L) / L;
}

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> L >> T;
    for(int i=1; i<=n; ++i){
        cin >> a[i] >> b[i];
        if(b[i] == 1) v1.emp(i);
        else v2.emp(i);
        cnt[i] = i;
    }
    T <<= 1;

    if(!v1.empty() && !v2.empty()){
        queue<int> q;
        for(int ri=0,rj=0; ri<v1.size(); ++ri){
            if(ri == 0){
                while(calc(v1[ri], v2[rj]) == T / L){
                    rj = (rj + 1) % v2.size();
                    if(rj == 0) break;
                }
            }
        
            int i = v1[ri];
            while(!q.empty() && calc(i, q.front()) == T / L) q.pop();
            while(q.size() < v2.size() && calc(i, v2[rj]) > T / L){
                q.push(v2[rj]);
                rj = (rj + 1) % v2.size();
            }
            cnt[i] = i + (T / L + 1) * q.size() + (T / L) * (v2.size() - q.size());
            cnt[i] = (cnt[i] % n + n - 1) % n + 1;
        }
    
        while(!q.empty()) q.pop();
        for(int ri=v2.size()-1,rj=v1.size()-1; ri>=0; --ri){
            if(ri == v2.size()-1){
                while(calc(v1[rj], v2[ri]) == T / L){
                    rj = (rj - 1 + v1.size()) % v1.size();
                    if(rj == v1.size()-1) break;
                }
            }
        
            int i = v2[ri];
            while(!q.empty() && calc(q.front(), i) == T / L) q.pop();
            while(q.size() < v1.size() && calc(v1[rj], i) > T / L){
                q.push(v1[rj]);
                rj = (rj - 1 + v1.size()) % v1.size();
            }
            cnt[i] = i - (T / L + 1) * q.size() - (T / L) * (v1.size() - q.size());
            cnt[i] = (cnt[i] % n + n - 1) % n + 1;
        }
    }

    for(int i=1; i<=n; ++i) ans[cnt[i]] = (a[i] + (b[i] == 1 ? 1 : -1) * (T >> 1) % L + L) % L;
    for(int i=1; i<=n; ++i) printf("%lld\n", ans[i]);
    return 0;
}