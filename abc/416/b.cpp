#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
string s;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]=='.'){
			if(i==0||s[i-1]=='#')
				s[i]='o';
		}
	}
	cout<<s<<'\n';
	return 0;
}
