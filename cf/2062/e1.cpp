#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn=4e5+45;
int n,a[kn],rp[kn],dfn[kn],dft=0,siz[kn];
vector<int> c[kn];
void dfs(int u,int b){
	siz[u]=1;
	dfn[u]=++dft;
	for(auto v: c[u]){
		if(v==b) continue;
		dfs(v,u);
		siz[u]+=siz[v];
	}
}
int tt[kn],t[kn],pos[kn];
inline int lb(const int& x){ return -x&x; }
inline void upd(int x,int w){
	int y=x;
	tt[x]=w;
	for(;x<=n;x+=lb(x)){
		if(w>t[x]){
			pos[x]=y;
			t[x]=w;
		}
	}
}
inline int qry(int x,int y){
	int res=0,ps=x;
	while(y>=x){
		if(y-lb(y)+1>=x){
			if(t[y]>res){
				res=t[y];
				ps=pos[y];
			}
			y-=lb(y);
		}
		else{
			if(tt[y]>res){
				res=tt[y];
				ps=y;
			}
			--y;
		}
	}
	return res;
}
vector<int> ans;
queue<pair<int,int> > qu;
inline void _solv(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1,x,y;i<n;++i){
		cin>>x>>y;
		c[x].emp(y);
		c[y].emp(x);
	}
	dfs(1,0);
	iota(rp+1,rp+n+1,1);
	sort(rp+1,rp+n+1,[](int x,int y){ return a[x]>a[y]; });
	for(int I=1;I<=n;++I){
		int i=rp[I];
		if(a[i]!=a[rp[I-1]]){
			while(!qu.empty()){
				pair<int,int> u=qu.front(); qu.pop();
				upd(u.first, u.second);
			}
		}
//		int pos1=qry(1,dfn[i]-1),pos2=qry(dfn[i]+siz[i],n));
//		int ps=(tt[pos1]>tt[pos2]?pos1:pos2);
		int res=max(qry(1,dfn[i]-1), qry(dfn[i]+siz[i],n));
		qu.push(make_pair(dfn[i],res+1));
		if(res==1){
			ans.emp(i);
		}
	}
	sort(ans.begin(),ans.end());
	printf("%ld ",ans.size());
	for(auto u: ans){
		printf("%d ",u);
	}
	printf("\n");
	for(int i=1;i<=n;++i){
		t[i]=tt[i]=a[i]=dfn[i]=rp[i]=siz[i]=pos[i]=0;
		c[i].clear();
	}
	while(!qu.empty()) qu.pop();
	dft=0;
	ans.clear();
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
