#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string a;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>a;
	for(int i=a.size()-1;i>=1;--i){
		if(a[i-1]=='W'&&a[i]=='A'){
			a[i-1]='A';
			a[i]='C';
		}
	}
	cout<<a<<'\n';
	return 0;
}
