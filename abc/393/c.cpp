#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,m;
unordered_map<int,int> mp[kn];
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i) mp[i][i]=1;
	int ans=0;
	for(int i=1,x,y;i<=m;++i){
		cin>>x>>y;
		if(x>y) swap(x,y);
		if(mp[x].count(y)) ++ans;
		else mp[x][y]=1;
	}
	printf("%d\n",ans);
	return 0;
}
