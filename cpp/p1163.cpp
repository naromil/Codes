#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll w0,w,m;
bool check(double mid){ // 是否还得完
	double ws=w0;
	for(int i=1;i<=m;++i) ws=ws*(mid+1.0)-w;
	return ws<=0.0;
}
signed main(){
	cin>>w0>>w>>m;
	double l=0,r=1000000,ans=0;
	while(l+0.0001<=r){
		double mid=(l+r)/2.0;
		if(check(mid)) l=mid+0.0001, ans=l;
		else r=mid-0.0001;
	}
	cout<<fixed<<setprecision(1)<<ans*100.0<<'\n';
	return 0;
}
