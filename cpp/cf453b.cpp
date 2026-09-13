#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 1e2 + 12, N = 65536, inf = 0x3f3f3f3f;
int n, a[kn], f[kn][N], b[kn][N];
int pr[16] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
int v[kn];

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n;
    for(int w=1; w<=60; ++w){
        for(int j=0; j<16; ++j){
            if(w * pr[j] <= 60) v[w*pr[j]] |= (1 << j);
        }
    }

    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        for(int j=0; j<N; ++j){
            for(int w=1; w<=60; ++w){
                if(j & v[w]) continue;
                if(f[i][j|v[w]] > f[i-1][j] + abs(a[i] - w)){
                    f[i][j|v[w]] = f[i-1][j] + abs(a[i] - w);
                    b[i][j|v[w]] = w;
                }
            }
        }
    }
    
    int jj = 0;
    for(int j=0; j<N; ++j){
        if(f[n][j] <= f[n][jj]) jj = j;
    }
    stack<int> stk;
    for(int i=n; i>=1; --i){
        stk.push(b[i][jj]);
        jj ^= v[b[i][jj]];
    }
    while(!stk.empty()){
        printf("%d ", stk.top());
        stk.pop();
    }
    printf("\n");
    return 0;
}