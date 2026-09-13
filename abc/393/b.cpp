#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=108;
int n;
string a;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>a;
	n=a.size();
	a=" "+a;
	int ans=0;
	for(int i=1;i<=n;++i) for(int j=i;j<=n;++j) for(int k=j;k<=n;++k){
		if(k-j!=j-i) continue;
		if(a[i]=='A'&&a[j]=='B'&&a[k]=='C') ++ans;
	}
	printf("%d\n",ans);
	return 0;
}
