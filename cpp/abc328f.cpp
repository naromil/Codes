#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,q,fu[kn];
ll dis[kn];
int find(int x){
	if(fu[x]==x) return x;
	int ff=fu[x];
	fu[x]=find(fu[x]);
	dis[x]+=dis[ff];
	return fu[x];
}
bool _uni(int x,int y,int w){
	int fx=find(x),fy=find(y);
	if(fx==fy) return (dis[x]-dis[y]==w);
	fu[fx]=fy;
	dis[fx]=w-dis[x]+dis[y];
	return true;
}
signed main(){
	scanf("%d %d",&n,&q);
	vector<int> ans;
	for(int i=1;i<=n;++i) fu[i]=i;
	for(int i=1;i<=q;++i){
		int x,y,w; scanf("%d %d %d",&x,&y,&w);
		if(_uni(x,y,w)) ans.emplace_back(i);
	}
	for(auto ntr: ans) printf("%d ",ntr);
	return 0;
}
