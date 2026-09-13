#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 1e6 + 16;
int n, nxt[kn], num[kn];
ll a[kn], df[kn], ans[kn];

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        a[i+n] = a[i];
        ans[0] += a[i];
    }
    stack<int> stk;
    for(int i=(n<<1); i>=1; --i){
        while(!stk.empty() && a[stk.top()] >= a[i]) stk.pop();
        nxt[i] = stk.empty() ? 0 : stk.top();
        stk.push(i);
    }
    
    for(int i=1; i<=(n<<1); ++i){
        if(!nxt[i]) continue;
        int j = nxt[i], w = (i <= n) ? 0 : num[i-n];
        num[i] += (i <= n);
        num[j] += num[i];
        df[j-i+w] -= (a[i] - a[j]);
        df[j-i+w+num[i]] += (a[i] - a[j]);
    }
    
    for(int i=1; i<=n; ++i){
        df[i] += df[i-1];
        ans[i] = df[i] + ans[i-1];
        printf("%lld\n", ans[i]);
    }
    return 0;
}