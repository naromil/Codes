#include<bits/stdc++.h>
using namespace std;
using ll=long long;
signed main(){
	int T; cin>>T;
	while(T--){
		int n,a,b; cin>>n>>a>>b;
		if(n%2==a%2&&n%2==b%2) printf("YES\n");
		else if(n%2==b%2&&a<b) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
