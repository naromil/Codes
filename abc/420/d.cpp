#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn=505,km=kn*kn*2;
int n,m,dis[km];
vector<int> c[km];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
char a[kn][kn];
inline int getid(int i,int j){ return (i-1)*m+j; }
inline bool chk(int i,int j){ return (i>=1&&i<=n&&j>=1&&j<=m&&a[i][j]!='#'); }
inline void bfs(){
	memset(dis,0x3f,sizeof dis);
	queue<int> q;
	q.push(n*m*2+1);
	dis[n*m*2+1]=0;
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(auto v: c[u]){
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i){ for(int j=1;j<=m;++j){ cin>>a[i][j]; } }
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(!chk(i,j)) continue;
			int id=getid(i,j),x=i,y=j;
			for(int k=0;k<4;++k){
				int nx=x+dx[k],ny=y+dy[k],nid=getid(nx,ny);
				if(!chk(nx,ny)) continue;
				if(a[nx][ny]=='.'||a[nx][ny]=='G'||a[nx][ny]=='S'){ c[id].emp(nid); c[id+n*m].emp(nid+n*m); }
				else if(a[nx][ny]=='x'){ c[id+n*m].emp(nid+n*m); }
				else if(a[nx][ny]=='o'){ c[id].emp(nid); }
				else if(a[nx][ny]=='?'){ c[id].emp(nid+n*m); c[id+n*m].emp(nid); }
			}
			if(a[x][y]=='S'){ c[n*m*2+1].emp(id); }
			else if(a[x][y]=='G'){ c[id].emp(n*m*2+2); c[id+n*m].emp(n*m*2+2); }
		}
	}
	bfs();
//	for(int i=1;i<=n*m*2+2;++i){
//		printf("EDGE %d: ",i);
//		for(auto v: c[i]) printf("%d ",v);
//		printf("\n%d\n",dis[i]);
//	}
//	printf("\n");
	int ans=dis[n*m*2+2]-2;
	printf("%d\n",(ans<1e9?ans:-1));
	return 0;
}
