#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll=long long;
using cit=const int&;
const int kn=552,km=kn*kn;
int n,m,q,a[kn][kn],b[km];
vector<int> rp;
inline int getid(int x,int y){ return (x-1)*m+y; }
inline pair<int,int> getps(int x){ return make_pair((x-1)/m+1,(x-1)%m+1); }
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int siz[km];
pair<int,int> fu[km];
int find(int x,int ver){
	if(fu[x].y>ver) return x;
	else return find(fu[x].x,ver);
}
inline void _union(int x,int y,int ver){
	int fx=find(x,ver), fy=find(y,ver);
	if(fx==fy) return;
	else if(siz[fx]<siz[fy]) swap(fx,fy);
	fu[fy]=make_pair(fx,ver);
	siz[fx]+=siz[fy];
	siz[fy]=0;
}
inline bool chk(int A,int B,int C,int D,int ver){ return find(getid(A,B),ver)==find(getid(C,D),ver); }
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
			b[getid(i,j)]=a[i][j];
			fu[getid(i,j)].y=0x3f3f3f3f;
			siz[getid(i,j)]=1;
			rp.emplace_back(getid(i,j));
		}
	}
	sort(rp.begin(),rp.end(),[](int x,int y){ return b[x]>b[y]; });
	for(int I=1;I<=n*m;++I){
		int i=rp[I-1];
		pair<int,int> u=getps(i);
		for(int k=0;k<4;++k){
			int nx=u.x+dx[k], ny=u.y+dy[k];
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]>=a[u.x][u.y]) _union(i, getid(nx,ny), I);
		}
	}
	cin>>q;
	for(int i=1;i<=q;++i){
		int A,B,Y,C,D,Z;
		cin>>A>>B>>Y>>C>>D>>Z;
		int lt=1,rt=n*m,at=n*m;
		while(lt<=rt){
			int mt=(lt+rt)>>1;
			if(chk(A,B,C,D,mt)){
				at=mt;
				rt=mt-1;
			}
			else lt=mt+1;
		}
		int X=b[rp[at-1]];
		if(X>=Y||X>=Z) printf("%d\n",abs(Y-Z));
		else printf("%d\n",Y-X+Z-X);
	}
	return 0;
}
