#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=25;
int n,K,X;
string a[kn];
multiset<string> st;
void dfs(int u,string str){
	if(u>K){
		st.insert(str);
		return;
	}
	for(int i=1;i<=n;++i){
		dfs(u+1,str+a[i]);
	}
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>K>>X;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	dfs(1,"");
	--X; while(X--) st.erase(st.begin());
	cout<<*st.begin()<<'\n';
	return 0;
}
