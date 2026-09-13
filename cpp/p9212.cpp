#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 1e5 + 15, inf = 0x3f3f3f3f;
int n, q, a[kn], A = -1, sq;
class Query{
    public: int l, r, x, y, m, i;
    bool operator < (const Query &v) const { return r < v.r; }
}qs[kn*10];
int cnt[320][320], suma[kn], sumb[320], ans[kn*5];
inline void upd(int x){
    int xb = x / sq;
    for(int i=x; i<=(xb+1)*sq-1; ++i) ++suma[i];
    for(int i=xb; i<=A/sq; ++i) ++sumb[i];
}
inline int qry(int x){
    int xb = x / sq;
    return suma[x] + (xb > 0 ? sumb[xb-1] : 0);
}
signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> q;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        A = max(A, a[i]);
    }
    sq = sqrt(A);
    int nq = q;
    for(int i=1; i<=q; ++i){
        cin >> qs[i].l >> qs[i].r >> qs[i].x >> qs[i].y >> qs[i].m;
        qs[i].x %= qs[i].m;
        qs[i].y %= qs[i].m;
        qs[i].i = i;
        if(qs[i].l == 1) continue;
        qs[++nq] = qs[i];
        qs[nq].l = 0;
        qs[nq].r = qs[i].l - 1;
    }
    swap(nq, q);
    sort(qs + 1, qs + q + 1);
    
    for(int i=1, j=0; i<=q; ++i){
        while(j < qs[i].r){ // a[j]<qs[i].l -> j<qs[i].r
            upd(a[++j]);
            for(int k=1; k<=sq; ++k) ++cnt[k][a[j]%k];
        }
        if(qs[i].x == qs[i].y) continue;
        int res = 0, p = qs[i].m, lt = p - qs[i].x, rt = p - qs[i].y - 1, len = rt - lt + (rt < lt ? p : 0);
        if(p <= sq){
            for(int k=lt; k<=lt+len; ++k) res += cnt[p][k%p];
        }
        else{
            for(int k=rt; k-len<=A; k+=p) res += qry(min(k, A)) - qry(max(k-len-1, 0));
        } // k=lt => k=rt
        ans[qs[i].i] += (qs[i].l == 0 ? -1 : 1) * res;
    }
    for(int i=1; i<=nq; ++i){
        printf("%d\n", ans[i]);
    }
    return 0;
}