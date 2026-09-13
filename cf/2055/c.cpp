#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
const int kn=1024;
int n,m,a[kn][kn],co[kn][kn];
string str;
inline void _calc(int sum){
	int x=1,y=1;
	for(int k=0;k<str.size();++k){
		if(str[k]=='D'){
			a[x][y]=sum;
			for(int j=1;j<=m;++j) if(j!=y) a[x][y]-=a[x][j];
			++x;
		}
		else{
			a[x][y]=sum;
			for(int i=1;i<=n;++i) if(i!=x) a[x][y]-=a[i][y];
			++y;
		}
	}
	return;
}
inline void _solv(){
	cin>>n>>m;
	if(n>1||m>1) cin>>str;
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j){
		cin>>a[i][j];
	}
	int X=1,Y=1;
	co[X][Y]=1;
	for(int k=0,tms=1;k<str.size();++k){
		if(str[k]=='D') ++X;
		else ++Y;
		if(k==str.size()-1 || str[k+1]!=str[k]){
			tms=co[X][Y]=-(tms-1);
		}
		else{
			co[X][Y]=1;
			++tms;
		}
	}
	if(co[n][m]==0) co[n][m]=1;
	int sum=0;
	_calc(sum);
	int sm1=sum, sm2=sum;
	for(int j=1;j<m;++j) sm1-=a[n][j];
	for(int i=1;i<n;++i) sm2-=a[i][m];
	if(!str.empty()&&str.back()=='D') sum=(sm2-sm1)/co[n][m];
	else sum=(sm1-sm2)/co[n][m];
	_calc(sum);
	a[n][m]=sum;
	for(int j=1;j<m;++j) a[n][m]-=a[n][j];
//	printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa \n");
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			printf("%lld ",a[i][j]);
		}
		printf("\n");
	}
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
