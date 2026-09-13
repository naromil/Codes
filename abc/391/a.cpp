#include<bits/stdc++.h>
using namespace std;
using ll=long long;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	string str; cin>>str;
	for(int i=0;i<str.size();++i){
		if(str[i]=='N') str[i]='S';
		else if(str[i]=='S') str[i]='N';
		else if(str[i]=='E') str[i]='W';
		else if(str[i]=='W') str[i]='E';
	}
	cout<<str<<'\n';
	return 0;
}
