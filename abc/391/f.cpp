#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,m;
ll a[kn],b[kn],c[kn];
bool cmp(int x,int y){ return x>y; }
inline ll calc(int i,int j,int k){ return a[i]*b[j]+b[j]*c[k]+c[k]*a[i]; }
class NODE{
	public:
	ll x,y,z,w;
	bool operator < (const NODE& v) const {
		return w<v.w;
	}
};
namespace tmp{
	vector<NODE> vec;
	inline void main(){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				for(int k=1;k<=n;++k){
					printf("%lld ",calc(i,j,k));
					vec.push_back({i,j,k,calc(i,j,k)});
				}
				printf("\n");
			}
			printf("\n\n");
		}
		sort(vec.begin(),vec.end());
		for(int j=vec.size()-1;j>=0;--j){
			NODE u=vec[j];
			printf("%ld: %lld %lld %lld: %lld\n",vec.size()-j,u.x,u.y,u.z,u.w);
		}
	}
}
unordered_map<ll,bool> mp;
inline bool chk(int i,int j,int k){
	if(i>n||j>n||k>n) return false;
	ll id=(i-1ll)*n*n+(j-1ll)*n+k;
	if(!mp.count(id)) return mp[id]=true;
	else return false;
}
priority_queue<NODE> pq;
inline void _solv(){
	pq.push({1,1,1,calc(1,1,1)});
	for(int i=1;i<m;++i){
		int x=pq.top().x, y=pq.top().y, z=pq.top().z; pq.pop();
		if(chk(x+1,y,z)){ pq.push({x+1,y,z,calc(x+1,y,z)}); }
		if(chk(x,y+1,z)){ pq.push({x,y+1,z,calc(x,y+1,z)}); }
		if(chk(x,y,z+1)){ pq.push({x,y,z+1,calc(x,y,z+1)}); }
	}
	printf("%lld\n",pq.top().w);
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i) cin>>b[i];
	for(int i=1;i<=n;++i) cin>>c[i];
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp);
	sort(c+1,c+n+1,cmp);
//	tmp::main();
	_solv();
	return 0;
}
