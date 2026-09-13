#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 1e5 + 15, inf = 0x3f3f3f3f;
int n, sq, a[kn], lst[kn], cnt[kn], ans[kn];
vector<int> ln[kn];

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n;
    sq = sqrt(n);
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        ln[a[i]].emp(i);
    }

    for(int k=1; k<=sq; ++k){
        int res = 0;
        for(int i=1; i<=n; ++i)
            cnt[i] = 0;
        for(int i=1; i<=n; ++i){
            if(lst[a[i]] < i || i == ln[a[i]][0]){
                ++cnt[a[i]];
                ++res;
                lst[a[i]] = i + k;
            }
        }
        ans[k] = res;
    }

    for(int k=1; k<=n; ++k){
        if(ln[k].empty()) continue;
//        printf("%d: [%d %d]\n", k, sq, cnt[k]);
        int len = sq;
        while(cnt[k] > 1){
            int nlen = inf;
            for(int i=ln[k][0]; ; ){
                auto it = upper_bound(ln[k].begin(), ln[k].end(), i + len);
                if(it == ln[k].end()) break;
                nlen = min(nlen, *it - i);
                i = *it;
            }
            int pcnt = cnt[k];
            cnt[k] = 0;
            len = nlen;
            for(int i=ln[k][0]; ; ){
                ++cnt[k];
                auto it = upper_bound(ln[k].begin(), ln[k].end(), i + len);
                if(it == ln[k].end()) break;
                i = *it;
            }
            ans[len] += cnt[k] - pcnt;
//            printf("%d [%d %d]: ", k, len, cnt[k]); for(int i=1; i<=n; ++i){ printf("%d ", ans[i]); } printf("\n");
        }
    }

    for(int i=1; i<=n; ++i){
        if(i > sq) ans[i] += ans[i-1];
        printf("%d\n", ans[i]);
    }
    return 0;
}