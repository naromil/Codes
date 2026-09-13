#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,a[15];
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	n=5;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=2;i<=n;++i){
			swap(a[i],a[i-1]);
			bool flg=true;
			for(int k=2;k<=n;++k) if(a[k]<=a[k-1]){ flg=false; break; }
			swap(a[i],a[i-1]);
			if(flg){
				printf("Yes\n");
				return 0;
			}
	}
	printf("No\n");
	return 0;
}
