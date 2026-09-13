#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,m,fu[kn];
class EDGE{ public: int x,y,i; }e[kn];
int find(int x){ return fu[x]==x?x:fu[x]=find(fu[x]); }
vector<int> eds,vec;
vector<EDGE> ans;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i) fu[i]=i;
	for(int i=1;i<=m;++i){
		cin>>e[i].x>>e[i].y;
		int fx=find(e[i].x), fy=find(e[i].y);
		if(fx!=fy){ fu[fy]=fx; }
		else{ eds.emp(i); }
	}
	for(int i=1;i<=n;++i){
		if(fu[i]!=i) continue;
		vec.emp(i);
	}
	for(auto i: eds){
		if(vec.size()==1) break;
		int x=e[i].x, ps=vec.size()-1;
		if(vec[ps]==find(x)) --ps;
		ans.push_back({x,vec[ps],i});
		fu[vec[ps]]=find(x);
		int tmp=vec.back();
		vec.pop_back();
		if(tmp==find(x)){
			vec.pop_back();
			vec.push_back(tmp);
		}
	}
	printf("%ld\n",ans.size());
	for(auto u: ans){
		printf("%d %d %d\n",u.i,u.x,u.y);
	}
	return 0;
}
