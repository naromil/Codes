#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
const int kN=3e5+23;
int n,tot,len;
vector<int> nbr[kN];
char a[kN];
ull pat=0,ds[kN];
inline void prep(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n; tot=n;
	for(int i=2;i<=n;i++){
		int cur; string str; cin>>cur>>str;
		for(int j=0;j<str.size();j++){
			int cc=(j==str.size()-1) ? i : ++tot;
			nbr[cur].push_back(cc);
			a[cur=cc]=str[j];
		}
	}
	ds[0]=1; for(int i=1;i<=m;i++) ds[i]=ds[i-1]*37ull;
	string str; cin>>str; len=str.size();
	for(int j=0;j<str.size();j++) pat=pat*ds[1]+(ull)(str[j]-'a'+1);
}
int dep[kN];
ull way[kN];
ll ans=0;
inline void dfs(int cur,int pre){
	dep[cur]=dep[pre]+1;
	if(pre) way[dep[cur]]=way[dep[pre]]*ds[1]+(ull)(a[cur]-'a'+1);
	if(dep[cur]-len>0) ans+=(way[dep[cur]]-way[dep[cur]-len]*ds[len]==pat);
	for(auto nxt: nbr[cur]) dfs(nxt,cur);
}
signed main(){
	prep();
	dfs(1,0);
	cout<<ans<<'\n';
	return 0;
}
