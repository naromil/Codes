#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,m,M,f[262144][20];
char a[kn][20];
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m; M=1<<m;
	for(int i=1;i<=n;++i){
		int A=0;
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
			A=(A<<1)+a[i][j]-'0';
		}
		++f[A][0];
	}
	for(int i=0;i<m;++i){
		for(int j=m-1;j>=0;--j){
			for(int k=0;k<M;++k){
				f[k^(1<<i)][j+1]+=f[k][j];
			}
		}
	}
	int ans=0x3f3f3f3f;
	for(int k=0;k<M;++k){
		int sum=0;
		for(int j=0;j<=m;++j){
			sum+=f[k][j]*min(j,m-j);
		}
		ans=min(ans,sum);
	}
	printf("%d\n",ans);
	return 0;
}
