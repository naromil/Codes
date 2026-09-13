#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,a[kn],m,b[kn];
bool cmp(int x,int y){ return x>y; }
signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    ll ans=0,sum=0,cur=0;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(a[i]>0) sum+=a[i];
    }
    for(int i=1;i<=m;++i){
        cin>>b[i];
    }
    ans=sum;
    sort(a+1,a+n+1,cmp);
    sort(b+1,b+m+1,cmp);
    for(int i=1;i<=n&&i<=m;++i){
        if(a[i]>0) sum-=a[i];
        cur+=a[i]+b[i];
        ans=max(ans,cur+sum);
    }
    printf("%lld\n",ans);
    return 0;
}
