#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a,b,c;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>a>>b>>c;
	if(a*b==c||a*c==b||b*c==a) printf("Yes\n");
	else printf("No\n");
	return 0;
}
