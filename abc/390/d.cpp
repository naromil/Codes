#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=16;
int n,vis[kn],ans=0;
ll a[kn];
unordered_map<ll,int> mp;
void dfs(const int& u,const ll& w){
	if(!u){
		if(!mp.count(w)){
			mp[w]=1;
			++ans;
		}
		return;
	}
	dfs(u-1,w^a[u]);
	for(int i=1;i<u;++i){
		if(!vis[i]){
			vis[i]=1;
			a[i]+=a[u];
			dfs(u-1,w);
			vis[i]=0;
			a[i]-=a[u];
		}
	}
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	dfs(n,0);
	printf("%d\n",ans);
	return 0;
}
