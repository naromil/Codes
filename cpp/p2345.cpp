#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll=long long;
const int kn=5e4+24;
int n;
class COW{
	public: int v,a;
	bool operator < (const COW &nxt) const{ return a<nxt.a; }
}a[kn];
ll ans=0;
int sum[kn],cnt[kn];
int lowbit(const int &x){ return -x&x; }
void update(int x,int y){
	if(!x) return;
	for(;x<=5e4;x+=lowbit(x)) sum[x]+=y, ++cnt[x];
}
pair<int,int> query(int x){
	pair<int,int> ret=make_pair(0,0);
	for(;x;x-=lowbit(x)) ret.x+=sum[x], ret.y+=cnt[x];
	return ret;
}
void solve1(){
	for(int i=1;i<=n;++i){
		pair<int,int> ret=query(a[i].v);
		ans+=1ll*a[i].v*(ret.y*a[i].a-ret.x);
		update(a[i].v,a[i].a);
	}
}
void solve2(){
	for(int i=n;i>=1;--i){
		pair<int,int> ret=query(a[i].v-1);
		ans+=1ll*a[i].v*(ret.x-ret.y*a[i].a);
		update(a[i].v,a[i].a);
	}
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i].v>>a[i].a;
	sort(a+1,a+n+1);
	solve1();
	memset(sum,0,sizeof(sum));
	memset(cnt,0,sizeof(cnt));
	solve2();
	cout<<ans<<'\n';
	return 0;
}
