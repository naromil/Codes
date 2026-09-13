#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=5e5+55;
int n,f[kn],lst[kn],pre[kn];
string a;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>a; n=a.size(); reverse(a.begin(),a.end()); a=" "+a;
	for(int i=1;i<=n;++i){
		if(i>1&&a[i]==a[i-1]) f[i]=i-1;
		else f[i]=i;
		int j=i-1;
		while(j){
			int len=j-f[j]+1;
			if(a[i-len-1]==a[i]){
				f[i]=i-len-1;
				break;
			}
			j=pre[j];
		}
		pre[i]=lst[f[i]];
		lst[f[i]]=i;
	}
	int m=1;
	for(int i=1;i<=n;++i){
		if(f[i]==1) m=i;
	}
	for(int i=n;i>m;--i) printf("%c",a[i]);
	for(int i=1;i<=n;++i) printf("%c",a[i]);
	printf("\n");
	return 0;
}
