#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i){
		if(i*2==n||i*2==n+1||i*2==n+2) printf("=");
		else printf("-");
	}
	printf("\n");
	return 0;
}
