#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=4e5+45;
int n,a[kn],b[kn],ans[kn];
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>b[i];
	}
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		ans[a[i]]=a[b[i]];
	}
	for(int i=1;i<=n;++i) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
