#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=1024;
int n,m,minx,maxx,miny,maxy;
char a[kn][kn];
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	minx=miny=114514;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
			if(a[i][j]=='#'){
				minx=min(minx, i);
				maxx=max(maxx, i);
				miny=min(miny, j);
				maxy=max(maxy, j);
			}
		}
	}
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j){
		if(i>=minx&&i<=maxx&&j>=miny&&j<=maxy&&a[i][j]=='.'){ printf("No\n"); return 0; }
	}
	printf("Yes\n");
	return 0;
}
