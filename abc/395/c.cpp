#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,a[kn],lst[1145141],ans=0x3f3f3f3f;
signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(lst[a[i]]) ans=min(ans,i-lst[a[i]]+1);
        lst[a[i]]=i;
    }
    if(ans!=0x3f3f3f3f) printf("%d\n",ans);
    else printf("-1\n");
}
