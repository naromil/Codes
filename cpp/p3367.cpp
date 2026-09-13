#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,q,siz[kn];
pair<int,int> fu[kn];
int find(int x,int ver){
	if(fu[x].y>ver) return x;
	else return find(fu[x].x,ver);
}
inline void _union(int x,int y,int ver){
	int fx=find(x,ver), fy=find(y,ver);
	if(fx==fy) return;
	else if(siz[fy]>siz[fx]) swap(fx,fy);
	fu[fy]=make_pair(fx,ver);
	siz[fx]+=siz[fy];
	siz[fy]=0;
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		siz[i]=1;
		fu[i].second=0x3f3f3f3f;
	}
	int ver=0;
	for(int i=1,op,x,y;i<=q;++i){
		cin>>op>>x>>y;
		if(op==1){
			_union(x,y,++ver);
		}
		else{
			printf(find(x,ver)==find(y,ver)?"Y\n":"N\n");
		}
	}
	return 0;
}
