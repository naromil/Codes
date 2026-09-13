#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,f[kn][5];
vector<int> c[kn];
bool cmp(int x,int y){ return x>y; }
void dfs(int u,int b){
	f[u][0]=1;
	vector<int> f3;
	for(auto v: c[u]){
		if(v==b) continue;
		dfs(v,u);
		f3.emplace_back(max(f[v][0],f[v][3]));
	}
	sort(f3.begin(),f3.end(),cmp);
	if(f3.size()>=1) f[u][1]=f[u][0]+f3[0];
	if(f3.size()>=3) f[u][3]=f[u][1]+f3[1]+f3[2];
	if(f3.size()>=4) f[u][4]=f[u][3]+f3[3];
}
int ans=2;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n;
	for(int i=2,x,y;i<=n;++i){
		cin>>x>>y;
		c[x].emplace_back(y);
		c[y].emplace_back(x);
	}
	dfs(1,0);
	for(int i=1;i<=n;++i){
		ans=max(ans,max(f[i][1],f[i][4]));
	}
	if(ans<=2) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}
