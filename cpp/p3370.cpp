#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
const int kN=1e4+11;
int n;
set<ull> st;
inline ull get_hash(string str){
	ull ret=0ull;
	for(int i=0;i<str.size();i++){
		ret=ret*512ull+(ull)str[i];
	}
	return ret;
}
inline void prep(){
	cin>>n;
	for(int i=1;i<=n;i++){
		string tmp; cin>>tmp;
		st.insert(get_hash(tmp));
	}
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	prep();
	cout<<st.size()<<'\n';
	return 0;
}
