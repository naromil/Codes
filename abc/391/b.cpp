#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=55;
int n,m;
char a[kn][kn],b[kn][kn];
inline bool chk(int x,int y){
	for(int i=1;i<=m;++i) for(int j=1;j<=m;++j){
		if(a[i+x-1][j+y-1]!=b[i][j]) return false;
	}
	return true;
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) cin>>a[i][j];
	for(int i=1;i<=m;++i) for(int j=1;j<=m;++j) cin>>b[i][j];
	for(int i=1;i<=n-m+1;++i) for(int j=1;j<=n-m+1;++j) if(chk(i,j)){
		printf("%d %d\n",i,j);
		break;
	}
	return 0;
}
