#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=55;
int n;
char a[kn][kn];
bool col[kn][kn][kn],row[kn][kn][kn];
void prep(){
	cin.tie(0) -> ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) cin>>a[i][j];
	for(int i=1;i<=n;++i) for(int l=1;l<=n;++l){
		int r=l; while(r<=n&&a[i][r]!='#') row[i][l][r++]=true;
	}
	for(int i=1;i<=n;++i) for(int l=1;l<=n;++l){
		int r=l; while(r<=n&&a[r][i]!='#') col[i][l][r++]=true;
	}
}
int f[kn][kn][kn][kn]; // f[i][j][k][l]: from (i,j) to (k,l)
signed main(){
	prep();
	for(int k=1;k<=n;++k) for(int l=1;l<=n;++l) for(int i=k;i>=1;--i) for(int j=l;j>=1;--j)
		f[i][j][k][l]=0x3f3f3f3f;
	for(int k=1;k<=n;++k) for(int l=1;l<=n;++l) for(int i=k;i>=1;--i) for(int j=l;j>=1;--j){
		f[i][j][k][l]=max(k-i+1,l-j+1);
		for(int o=i;o<=k;++o) if(row[o][j][l])
			f[i][j][k][l]=min(f[i][j][k][l], f[i][j][o-1][l] + f[o+1][j][k][l]);
		for(int o=j;o<=l;++o) if(col[o][i][k])
			f[i][j][k][l]=min(f[i][j][k][l], f[i][j][k][o-1] + f[i][o+1][k][l]);
	}
	cout<<f[1][1][n][n]<<'\n';
	return 0;
}
