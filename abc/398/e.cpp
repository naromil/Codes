#include<bits/stdc++.h>
#define emp emplace_back
#define pii pair<int,int>
#define x first
#define y second
#define mp make_pair
using namespace std;
using ll=long long;
const int kn=108;
int n,col[kn],E[kn][kn];
vector<int> c[kn],A,B;
set<pii> st;
void dfs(int u,int b){
	if(col[u]==0) A.emp(u);
	else B.emp(u);
	for(auto v: c[u]){
		if(v==b) continue;
		col[v]=col[u]^1;
		dfs(v,u);
	}
}
inline void st_use(pii val){
	if(val.x>val.y) swap(val.x,val.y);
	auto it=st.find(val);
	if(it!=st.end()) st.erase(it);
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n;
	for(int i=2,x,y;i<=n;++i){
		cin>>x>>y;
		c[x].emp(y);
		c[y].emp(x);
		E[x][y]=E[y][x]=1;
	}
	col[1]=0;
	dfs(1,0);
	for(auto u: A){
		for(auto v: B){
			if(!E[u][v]&&u<v) st.insert(mp(u,v));
			if(!E[u][v]&&v<u) st.insert(mp(v,u));
		}
	}
	if(st.size()&1){
		printf("First\n");
		printf("%d %d\n",st.begin()->x,st.begin()->y);
		fflush(stdout);
		st_use(*st.begin());
	}
	else{
		printf("Second\n");
		fflush(stdout);
	}
	int xx,yy;
	while(cin>>xx>>yy){
		if(xx==-1&&yy==-1) break;
		if(xx>yy) swap(xx,yy);
		st_use(mp(xx,yy));
		printf("%d %d\n",st.begin()->x,st.begin()->y);
		fflush(stdout);
		st_use(*st.begin());
	}
	return 0;
}
