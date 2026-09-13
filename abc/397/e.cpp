#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,m;
vector<int> c[kn];
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	n*=m;
	for(int i=1,x,y;i<n;++i){
		cin>>x>>y;
		c[x].emplace_back(y);
		c[y].emplace_back(x);
	}
	dfs(1,0);
	return 0;
}
