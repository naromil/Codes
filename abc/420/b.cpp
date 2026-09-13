#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=108;
int n,m,ans[kn];
char a[kn][kn];
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) cin>>a[i][j];
	for(int j=1;j<=m;++j){
		int cnt=0,flg=-1;
		for(int i=1;i<=n;++i){
			if(a[i][j]=='1') ++cnt;
		}
		if(cnt==n||cnt==0) flg=-1;
		else if(cnt>n-cnt) flg=1;
		else flg=0;
		for(int i=1;i<=n;++i){
			if(a[i][j]-'0'!=flg) ++ans[i];
		}
	}
	int maxi=-1;
	for(int i=1;i<=n;++i){
		maxi=max(maxi,ans[i]);
	}
	for(int i=1;i<=n;++i){
		if(ans[i]==maxi) printf("%d ",i);
	}
	printf("\n");
	return 0;
}
