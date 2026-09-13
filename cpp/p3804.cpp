#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e6 + 26;
class SAM{
    public:
    struct STA{ int ln, lk, nx[26]; }a[kn];
    int tt, la, sz[kn], in[kn];
    SAM(){ tt = la = 1; }
    inline void exp(int ch){
        int i = la;
        sz[la=++tt] = 1;
        a[la].ln = a[i].ln + 1;
        while(i && !a[i].nx[ch]){
            a[i].nx[ch] = la;
            i = a[i].lk;
        }
        if(!i){
            a[la].lk = 1;
            return;
        }
        int j = a[i].nx[ch];
        if(a[i].ln + 1 == a[j].ln){
            a[la].lk = j;
            return;
        }
        a[++tt] = a[j];
        a[tt].ln = a[i].ln + 1;
        a[j].lk = a[la].lk = tt;
        for(; a[i].nx[ch]==j; i=a[i].lk) a[i].nx[ch] = tt;
    }
    inline ll sol(){
        queue<int> q;
        ll res = 0;
        for(int i=1; i<=tt; ++i) ++in[a[i].lk];
        for(int i=1; i<=tt; ++i) if(!in[i]) q.push(i);
        while(!q.empty()){
            int i = q.front(); q.pop();
            sz[a[i].lk] += sz[i];
            if(sz[i] > 1) res = max(res, 1ll * a[i].ln * sz[i]);
            if(!--in[a[i].lk]) q.push(a[i].lk);
        }
        return res;
    }
}M;

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    string str; cin >> str;
    for(int j=0; j<str.size(); ++j) M.exp(str[j] - 'a');
    printf("%lld\n", M.sol());
    return 0;
}