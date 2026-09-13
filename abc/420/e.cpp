#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,q,fu[kn],cnt[kn],a[kn];
int find(int x){ return fu[x]==x?x:fu[x]=find(fu[x]); }
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;++i){ fu[i]=i; }
	for(int i=1,op,u,v;i<=q;++i){
		cin>>op>>u;
		if(op==1){
			cin>>v;
			int fx=find(u), fy=find(v);
			if(fx!=fy){ fu[fy]=fx; cnt[fx]+=cnt[fy]; cnt[fy]=0; }
		}
		else if(op==2){
			if(a[u]) --cnt[find(u)];
			else ++cnt[find(u)];
			a[u]^=1;
		}
		else{
			if(cnt[find(u)]) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}
