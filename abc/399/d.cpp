#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=4e5+45;
vector<int> ps[kn];
int n,b[kn];
inline bool chk(int x,int y){ return (x>=1&&x<=(n<<1)&&y>=1&&y<=(n<<1)&&abs(x-y)>1&&b[x]==b[y]); }
inline void _solv(){
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;++i) ps[i].clear();
	for(int i=1;i<=(n<<1);++i){
		cin>>b[i];
		ps[b[i]].emplace_back(i);
	}
	for(int i=1;i<=n;++i){
		int u=ps[i][0], v=ps[i][1];
		if(u+1==v||v+1==u) continue;
		if(chk(u+1,v+1)) ++ans;
		if(chk(u+1,v-1)) ++ans;
		if(chk(u-1,v+1)) ++ans;
		if(chk(u-1,v-1)) ++ans;
	}
	printf("%d\n",ans>>1);
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
