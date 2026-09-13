#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=55555;
unordered_map<string,int> nbr[kn];
int n,tot=0;
void insert(const string &str){
	string upd;
	int cur=0;
	for(int i=1;i<str.size();++i){
		if(str[i]=='/'){ upd=""; continue; }
		upd+=str[i];
		if(i==str.size()-1 || str[i+1]=='/'){
			if(!nbr[cur][upd]) nbr[cur][upd]=++tot;
			cur=nbr[cur][upd];
		}
	}
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i){
		string str; cin>>str;
		insert(str);
		cout<<tot<<'\n';
	}
	return 0;
}
