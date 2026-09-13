#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll=long long;
const int kn=1e4+14;
int n;
pair<double,double> a[kn];
double get_dis(int i,int j){ return sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y)); }
double dac(int l,int r){
	if(l==r) return 1ll<<36;
	int mid=(l+r)>>1;
	double dis=min(dac(l,mid), dac(mid+1,r));
	vector<int> rts;
	for(int i=l;i<=r;++i) if(fabs(a[i].x-a[mid].x)<=dis)
		rts.emplace_back(i);
	sort(rts.begin(),rts.end(),[](const int &x,const int &y){ return a[x].y<a[y].y; });
	for(int i=0;i<rts.size();++i) for(int j=i+1;j<rts.size()&&a[rts[j]].y-a[rts[i]].y<=dis;++j)
		dis=min(dis,get_dis(rts[i],rts[j]));
	return dis;
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i].x>>a[i].y;
	sort(a+1,a+n+1);
	cout<<fixed<<setprecision(4)<<dac(1,n)<<'\n';
	return 0;
}
