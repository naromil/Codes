#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2048;
int n,m,a[kn][kn],p[kn*kn];
inline void _solv(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
			p[a[i][j]+1]=i;
		}
	}
	for(int i=1;i<=n;++i){
		int cr=p[i];
		for(int j=1;j<m;++j){
			if(p[i+j*n]!=cr){
				printf("-1\n");
				return;
			}
		}
	}
	for(int i=1;i<=n;++i){
		printf("%d ",p[i]);
	}
	printf("\n");
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
