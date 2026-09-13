#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,a[kn];
signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=2;i<=n;++i){
        if(a[i]<=a[i-1]){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}
