#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll=long long;
const int kn=1e5+15;
int n=0;
pair<int,int> a[kn];
void prep(){
	static int m,b[kn];
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>m;
	for(int i=1;i<=m;++i) cin>>b[i];
	sort(b+1,b+m+1);
	for(int i=1;i<=m;++i){
		if(i==1||b[i]!=b[i-1]) a[++n].x=b[i];
		++a[n].y;
	}
}
signed main(){
	prep();
	deque<int> q;
	int ans=0x3f3f3f3f;
	for(int i=1;i<=n;++i){
		if(i==1 || a[i].x>a[i-1].x+1){
			while(!q.empty()) ans=min(ans,i-q.back()), q.pop_back();
			for(int j=1;j<=a[i].y;++j) q.push_back(i);
		}
		else{
			while(q.size()>a[i].y) ans=min(ans,i-q.front()), q.pop_front();
			for(int j=q.size()+1;j<=a[i].y;++j) q.push_back(i);
		}
	}
	while(!q.empty()) ans=min(ans,n-q.back()+1), q.pop_back();
	cout<<ans<<'\n';
	return 0;
}
