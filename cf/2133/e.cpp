#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,f[kn][5],ps1[kn],ps2[kn];
vector<int> c[kn];
void dfs(int u,int b){
	int Sfv4=0,Sfv1=0,mini1=0x3f3f3f3f,mini2=0x3f3f3f3f,pos1=0,pos2=0;
	for(auto v: c[u]){
		if(v==b) continue;
		dfs(v,u);
		Sfv4+=f[v][4];
		Sfv1+=f[v][1];
		if(f[v][0]-f[v][1]<mini1){
			pos2=pos1;
			mini2=mini1;
			pos1=v;
			mini1=f[v][0]-f[v][1];
		}
		else if(f[v][0]-f[v][1]<mini2){
			pos2=v;
			mini2=f[v][0]-f[v][1];
		}
	}
	ps1[u]=pos1;
	ps2[u]=pos2;
	f[u][1]=1+Sfv4;
	f[u][0]=min(Sfv1,Sfv1+mini1);
	f[u][2]=Sfv1+mini1+mini2;
	f[u][4]=min({f[u][0],f[u][1],f[u][2]});
}
int chs[kn],vis[kn];
vector<int> vec;
void bud(int u,int b,int op){
	if(c[u].size()==1&&c[u].front()==b) vec.emp(u);
	if(op==1){
		chs[u]=1;
		vec.emp(u);
		if(b) vec.emp(b);
		printf("%d %d\n",2,u);
		for(auto v: c[u]){
			if(v==b) continue;
			for(int i=0;i<=2;++i) if(f[v][i]==f[v][4]){ bud(v,u,i); break; }
		}
	}
	else if(op==0){
		int ps=0;
		if(f[ps1[u]][0]-f[ps1[u]][1]<0) ps=ps1[u];
		for(auto v: c[u]){
			if(v==b) continue;
			if(v==ps) bud(v,u,0);
			else bud(v,u,1);
		}
	}
	else if(op==2){
		int p1=ps1[u],p2=ps2[u];
		for(auto v: c[u]){
			if(v==b) continue;
			if(v==p1||v==p2) bud(v,u,0);
			else bud(v,u,1);
		}
	}
}
void prt(int u,int b){
	vis[u]=1;
	printf("%d %d\n",1,u);
	for(auto v: c[u]){
		if(v==b||chs[u]||chs[v]) continue;
		prt(v,u);
	}
}
inline void _solv(){
	cin>>n;
	vec.clear();
	for(int i=1;i<=n;++i){
		f[i][0]=f[i][1]=f[i][2]=f[i][4]=0x3f3f3f3f;
		ps1[i]=ps2[i]=chs[i]=vis[i]=0;
		c[i].clear();
	}
	for(int i=2,x,y;i<=n;++i){
		cin>>x>>y;
		c[x].emp(y);
		c[y].emp(x);
	}
	dfs(1,0);
	printf("%d\n",f[1][4]+n);
	for(int i=0;i<=2;++i) if(f[1][i]==f[1][4]){ bud(1,0,i); break; }
	for(auto u: vec){
		if(!vis[u]) prt(u,0);
	}
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T; while(T--) _solv();
	return 0;
}
