#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=9;
const ll inf=0x3f3f3f3f3f3f3f3f;
int n,m; ll p,ans=inf;
class EDGES{ public: int x,y; ll w; } e[kn*kn];
int dig[kn],fa[kn];
int find(const int& x){ return (fa[x]==x)?x:fa[x]=find(fa[x]); }
bool check(){
	for(int i=1;i<=n;++i) fa[i]=i;
//	for(int i=1;i<n;++i) cout<<dig[i]<<' ';
//	cout<<'\n';
	for(int i=1;i<n;++i){
		int x=e[dig[i]].x, y=e[dig[i]].y;
		if(find(x)==find(y)) return false;
		fa[find(y)]=find(x);
	}
	return true;
}
void dfs(const int& l,const int& cnt,const ll& sum){
	if(cnt==n){
		if(check()) ans=min(ans,sum%p);
		return;
	}
	for(int i=l;i<=m;++i){
		dig[cnt]=i;
		dfs(i+1,cnt+1,sum+e[i].w);
	}
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m>>p;
	for(int i=1;i<=m;++i) cin>>e[i].x>>e[i].y>>e[i].w;
	dfs(1,1,0);
	cout<<ans<<'\n';
	return 0;
}
