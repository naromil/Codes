#include<bits/stdc++.h>
#define emp emplace_back
#define mkp make_pair
#define fst first
#define scd second
#define pii pair<int,int>
using namespace std;
using ll=long long;
const int kn = 3e5 + 35;
int n, a[kn], b[kn];
vector<pii> blc;
vector<int> ps;
vector<pair<int, pii>> ans;

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=n; ++i) cin >> b[i];
    for(int i=1,pr=1,j=1; i<=n; ++i){
        if(b[i] != b[i+1]){
            blc.emp(mkp(pr, i));
            pr = i + 1;
            while(j <= n && a[j] != b[i])
                ++j;
            if(j == n + 1){ printf("NO\n"); return 0; }
            ps.emp(j);
        }
    }

    for(int i=0; i<blc.size(); ++i){
        if(blc[i].fst < ps[i]) ans.emp(mkp(0, mkp(blc[i].fst, ps[i])));
    }
    for(int i=blc.size()-1; i>=0; --i){
        if(blc[i].scd > ps[i]) ans.emp(mkp(1, mkp(ps[i], blc[i].scd)));
    }

    printf("YES\n%ld\n", ans.size());
    for(auto [op, cr]: ans)
        printf("%c %d %d\n", op ? 'R' : 'L', cr.fst - 1, cr.scd - 1);
    return 0;
}