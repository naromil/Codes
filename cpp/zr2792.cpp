#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
using ll=long long;
const int kN=1e5+23;
int n,q,a[kN];
int tit=0; unordered_map<int,int> tid; vector<int> tis[kN];
unordered_map<ll,ll> anss;
ll query(int x,int y){
	ll ans=0,cur=0; int sizx=tis[x].size(),sizy=tis[y].size();
	for(int i=0,j=0; i<sizx; i++){
		while(j<sizy && tis[y][j]<=tis[x][i]) j++;
		if(j==sizy) break;
		cur=(i+1ll)*(sizy-j);
		if(cur>ans) ans=cur;
	}
	return ans;
}
void prep(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(!tid[a[i]]) tid[a[i]]=++tit;
		tis[tid[a[i]]].push_back(i);
	}
}
ll ans[kN];
signed main(){
	prep();
	for(int i=1;i<=q;i++){
		int x,y; cin>>x>>y; x=tid[x], y=tid[y];
		ll cur=(x>y?-1ll:1ll)*(x-1)*tit+y;
		auto &it=anss[cur];
		if(!it) it=query(x,y);
		ans[i]=it;
	}
	for(int i=1;i<=q;i++) printf("%lld\n",ans[i]);
	return 0;
}

