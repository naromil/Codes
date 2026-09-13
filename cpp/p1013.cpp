#include<bits/stdc++.h>
using namespace std;
const int kn=24;
int n,nm[256];
bool mp[kn];
string s[kn][kn];
int conv(string &str){
	int ret=0;
	for(int i=0;i<str.size();++i){
		ret=ret*(n-1)+nm[str[i]];
	}
	return ret;
}
bool check(){
	for(int i=2;i<=n;++i){
		for(int j=2;j<=n;++j){
			if(conv(s[i][1])+conv(s[1][j])==conv(s[i][j]));
			else return false;
		}
	}
	return true;
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin>>s[i][j];
		}
	}
	for(int i=2;i<=n;++i){
		int nms=0;
		for(int j=2;j<=n;++j){
			nms+=(s[i][j].size()>=2);
		}
		if(mp[nms]){
			cout<<"ERROR!\n";
			return 0;
		}
		mp[nms]=true;
		nm[s[i][1][0]]=nms;
	}
	if(!check()){
		cout<<"ERROR!\n";
	}
	else{
		for(int i=2;i<=n;++i){
			cout<<s[i][1]<<'='<<nm[s[i][1][0]]<<' ';
		}
		cout<<'\n'<<n-1<<'\n';
	}
	return 0;
}
