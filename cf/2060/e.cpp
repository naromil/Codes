#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,m1,m2,Ix[kn],Iy[kn],fu[kn],fu2[kn],Ixx[kn],Iyy[kn];
int find(const int& x){
	return fu[x]==x?x:fu[x]=find(fu[x]);
}
int find2(const int& x){
	return fu2[x]==x?x:fu2[x]=find2(fu2[x]);
}
inline void _solv(){
	int ans=0;
	cin>>n>>m1>>m2;
	for(int i=1;i<=n;++i) fu[i]=fu2[i]=i;
	for(int i=1;i<=m1;++i){
		cin>>Ix[i]>>Iy[i];
	}
	for(int i=1;i<=m2;++i){
		cin>>Ixx[i]>>Iyy[i];
		int x=Ixx[i], y=Iyy[i];
		if(find(x)!=find(y)) fu[find(y)]=find(x);
	}
	for(int i=1;i<=m1;++i){
		int x=Ix[i], y=Iy[i];
		if(find(x)!=find(y)){
			++ans;
			continue;
		}
		if(find2(x)!=find2(y)) fu2[find2(y)]=find2(x);
	}
	for(int i=1;i<=m2;++i){
		int x=Ixx[i], y=Iyy[i];
		if(find2(x)!=find2(y)){
			++ans;
			fu2[find2(y)]=find2(x);
		}
	}
	printf("%d\n",ans);
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
