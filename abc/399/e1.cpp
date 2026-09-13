#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
const int kn=4e5+45;
int n,ans=0,vis[50];
string a,b;
vector<int> chs[50],c[50];
bool spa=false,lop=false,anylop=false;
void dfs(int u,int b){
	vis[u]=1;
	for(auto v: c[u]){
		if(v==b||v==u) continue;
		if(vis[v]) lop=true;
		else dfs(v,u);
	}
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>a>>b; a=" "+a; b=" "+b;
	for(int i=1;i<=n;++i){
		chs[a[i]-'a'].emplace_back(i);
	}
	for(int i=0;i<26;++i){
		if(chs[i].empty()){ spa=true; continue; }
		int k=-1;
		for(auto j: chs[i]){
			if(k==-1) k=b[j]-'a';
			else if(b[j]-'a'!=k){ printf("-1\n"); return 0; }
		}
		if(i==k) continue;
		c[i].emplace_back(k);
		c[k].emplace_back(i);
		++ans;
	}
	for(int i=0;i<26;++i){
		bool flg=false;
		for(auto v: c[i]){ if(v!=i) flg=true; }
		if(!flg) continue;
		if(!vis[i]){
			lop=false;
			dfs(i,-1);
			if(lop==true){
				++ans;
				anylop=true;
			}
			else{
				spa=true;
			}
		}
	}
	if(anylop&&!spa) printf("-1\n");
	else printf("%lld\n",ans);
	return 0;
}
