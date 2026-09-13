#include<bits/stdc++.h>
#define emp emplace_back
#define pii pair<int,int>
#define x first
#define y second
using namespace std;
using ll=long long;
const int kn = 1e5 + 15, mod = 1e9 + 7;
int inv[kn];

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    inv[0] = inv[1] = 1;
    for(int i=2; i<kn; ++i) inv[i] = inv[mod%i] * (mod - mod / i) % mod;
    int T; cin >> T;
    while(T--) _solv();
    return 0;
}