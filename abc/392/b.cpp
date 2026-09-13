#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,m,a[kn];
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1,x;i<=m;++i){
		cin>>x;
		a[x]=1;
	}
	printf("%d\n",n-m);
	for(int i=1;i<=n;++i){
		if(!a[i]) printf("%d ",i);
	}
	printf("\n");
	return 0;
}
