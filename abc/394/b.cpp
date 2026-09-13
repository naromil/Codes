#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n;
string a[kn];
bool cmp(string x,string y){
	return x.size()<y.size();
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;++i) cout<<a[i];
	cout<<'\n';
	return 0;
}
