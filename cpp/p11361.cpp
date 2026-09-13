#include<bits/stdc++.h>
#define FILE(x) freopen(#x".in","r",stdin), freopen(#x".out","w",stdout)
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 1e5 + 15;
int n, b1[kn], b2[kn], c10[kn], c11[kn], c20[kn], c21[kn];
string s1, s2, t1, t2;

inline void _solv(){
    memset(b1, 0, sizeof b1);
    memset(b2, 0, sizeof b2);
    cin >> n >> s1 >> s2 >> t1 >> t2;
    s1 = " " + s1; s2 = " " + s2; t1 = " " + t1; t2 = " " + t2;
    for(int i=1; i<=n; ++i){
        if(i == 1 || (t1[i] == '1' && t1[i-1] == '1')) b1[i] = b1[i-1];
        else b1[i] = i;
        if(i == 1 || (t2[i] == '1' && t2[i-1] == '1')) b2[i] = b2[i-1];
        else b2[i] = i;
        if(s1[i] == '0') ++c10[b1[i]];
        else ++c11[b1[i]];
        if(s2[i] == '0') ++c20[b2[i]];
        else ++c21[b2[i]];
    }
    int ans = 0;
    for(int i=1; i<=n; ++i){
        int i1 = b1[i], i2 = b2[i];
        if(c10[i1] && c20[i2]){
            --c10[i1];
            --c20[i2];
            ++ans;
        }
        else if(c11[i1] && c21[i2]){
            --c11[i1];
            --c21[i2];
            ++ans;
        }
        else if(c10[i1] && c21[i2]){
            --c10[i1];
            --c21[i2];
        }
        else{
            --c11[i1];
            --c20[i2];
        }
    }
    printf("%d\n", ans);
}
signed main(){
//    FILE(edit2);
    cin.tie(0)->ios::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) _solv();
    return 0;
}