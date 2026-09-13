#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn=1024;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int n,m,dis[kn][kn];
char a[kn][kn];
inline bool chk(int x,int y){
	return (x>=1&&x<=n&&y>=1&&y<=m);
}
inline void bfs(pii S){
	memset(dis,0x3f,sizeof dis);
	deque<pii> dq;
	dq.push_front(mp(S.x,S.y));
	dis[S.x][S.y]=0;
	while(!dq.empty()){
		int x=dq.front().x, y=dq.front().y; dq.pop_front();
		for(int k=0;k<4;++k){
			int nx=x+dx[k], ny=y+dy[k];
			if(chk(nx,ny)&&a[nx][ny]=='.'&&dis[nx][ny]>dis[x][y]){
				dis[nx][ny]=dis[x][y];
				dq.push_front(mp(nx,ny));
			}
			else if(chk(nx,ny)&&dis[nx][ny]>dis[x][y]+1){
				dis[nx][ny]=dis[x][y]+1;
				dq.push_back(mp(nx,ny));
			}
		}
		for(int k=0;k<4;++k){
			int nx=x+dx[k]*2, ny=y+dy[k]*2;
			if(chk(nx,ny)&&dis[nx][ny]>dis[x][y]+1){
				dis[nx][ny]=dis[x][y]+1;
				dq.push_back(mp(nx,ny));
			}
		}
	}
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
		}
	}
	pii S,T;
	cin>>S.x>>S.y>>T.x>>T.y;
	bfs(S);
	printf("%d\n",dis[T.x][T.y]);
	return 0;
}
