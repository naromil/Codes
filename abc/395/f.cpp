#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,m,a[kn],b[kn];
inline bool chk(int mt){
    int L=0,R=0x3f3f3f3f;
    for(int i=1;i<=n;++i){
        int w=a[i]+b[i]-mt;
        if(w<0) return false;
        int l=max(0,a[i]-w), r=a[i];
        if(l>R+m) return false;
        if(r<L-m) return false;
        L=max(l,L-m);
        R=min(r,R+m);
    }
    return true;
}
signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i]>>b[i];
    ll lt=0,rt=2e9,at=0;
    while(lt<=rt){
        ll mt=(lt+rt)>>1;
        if(chk(mt)){ lt=mt+1; at=mt; }
        else rt=mt-1;
    }
    ll ans=0;
    for(int i=1;i<=n;++i){ ans+=a[i]+b[i]-at; }
    printf("%lld\n",ans);
    return 0;
}
