#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int bs[10007];
signed main(){
	for(int i=1;i<=10000;i++) bs[i]=i*(i-1)>>1;
	int n; cin>>n;
	int pos=lower_bound(bs,bs+10001,n)-bs;
	int cur=n-bs[pos-1];
	int ans1=cur, ans2=pos-cur;
	if(!(pos&1)) swap(ans1,ans2);
	cout<<ans1<<'/'<<ans2<<'\n';
	return 0;
}
