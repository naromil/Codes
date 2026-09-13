#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=3e5+35;
int n,a[kn],rp[kn],ans[kn];
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i) rp[i]=i;
	sort(rp+1,rp+n+1,[](int x,int y){ return a[x]>a[y]; });
	for(int I=1,j=0;I<=n;++I){
		int i=rp[I];
		++j;
		ans[i]=(I>1&&a[rp[I-1]]==a[i])?ans[rp[I-1]]:j;
	}
	for(int i=1;i<=n;++i){
		printf("%d\n",ans[i]);
	}
	return 0;
}
