#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,q,a[kn],b[kn],c[kn];
ll ans=0;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;++i){ cin>>a[i]; }
	for(int i=1;i<=n;++i){
		cin>>b[i];
		c[i]=min(a[i],b[i]);
		ans+=c[i];
	}
	for(int i=1,x,w;i<=q;++i){
		char ch; cin>>ch>>x>>w;
		if(ch=='A'){
			int nc=min(w,b[x]);
			if(nc!=c[x]){
				ans=ans-c[x]+nc;
				c[x]=nc;
			}
			a[x]=w;
		}
		else{
			int nc=min(a[x],w);
			if(nc!=c[x]){
				ans=ans-c[x]+nc;
				c[x]=nc;
			}
			b[x]=w;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
