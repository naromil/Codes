#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=1e5+15;
int n,q;
class CIRC{
	public: int d,c;
}a[kn];
int fa[kn][20],sum[kn][20];
void prep(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>a[i].d>>a[i].c;
		sum[i][0]=a[i].c;
	}
	sum[0][0]=a[0].c=0x3f3f3f3f;
	stack<int> stk;
	for(int i=1;i<=n;++i){
		while(!stk.empty() && a[stk.top()].d<a[i].d) fa[stk.top()][0]=i, stk.pop();
		stk.push(i);
	}
	for(int k=1;k<20;++k) for(int i=1;i<=n;++i){
		sum[i][k]=sum[i][k-1]+sum[fa[i][k-1]][k-1];
		fa[i][k]=fa[fa[i][k-1]][k-1];
	}
}
signed main(){
	prep();
	vector<int> ans;
	for(int i=1;i<=q;++i){
		int r,v; cin>>r>>v;
		int cur=r;
		for(int k=19;k>=0;--k) if(sum[cur][k]<v) v-=sum[cur][k], cur=fa[cur][k];
		ans.emplace_back(cur);
	}
	for(auto ntr: ans) cout<<ntr<<'\n';
	return 0;
}
