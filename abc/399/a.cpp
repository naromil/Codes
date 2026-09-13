#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
string a,b;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>a>>b;
	int cnt=0;
	for(int i=0;i<n;++i){
		if(a[i]!=b[i]) ++cnt;
	}
	printf("%d\n",cnt);
	return 0;
}
