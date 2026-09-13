#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kq=2e5+25,kn=1e6+16;
int q,vis[kn],mi[kn];
vector<int> ans;
inline void _init(int n){
	vector<int> pr;
	for(int i=2;i<=n;++i){
		if(!vis[i]){
			mi[i]=i;
			pr.emplace_back(i);
		}
		for(auto j: pr){
			if(1ll*i*j>n) break;
			vis[i*j]=j;
			if(mi[i]==j) mi[i*j]=j;
			if(i%j==0) break;
		}
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]) continue;
		int x=i;
		while(x%vis[i]==0) x/=vis[i];
		if(mi[x]) ans.emplace_back(i);
	}
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	_init(1e6);
	cin>>q;
	for(int i=1;i<=q;++i){
		ll x; cin>>x; x=sqrt(x);
		int y=upper_bound(ans.begin(),ans.end(),x)-1-ans.begin();
		printf("%lld\n",1ll*ans[y]*ans[y]);
	}
	return 0;
}
