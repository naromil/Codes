#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,a[kn],vis[kn];
inline void _solv(){
	cin>>n;
	for(int i=1;i<=n;++i) vis[i]=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		++vis[a[i]];
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			int x;
			printf("? %d %d\n",i,1+(i==1));
			fflush(stdout);
			cin>>x;
			if(x) printf("! B\n");
			else printf("! A\n");
			fflush(stdout);
			return;
		}
	}
	int x,y,A,B;
	for(int i=1;i<=n;++i){
		if(a[i]==1) A=i;
		else if(a[i]==n) B=i;
	}
	printf("? %d %d\n",A,B);
	fflush(stdout);
	cin>>x;
	if(x<n-1) printf("! A\n");
	else{
		printf("? %d %d\n",B,A);
		fflush(stdout);
		cin>>y;
		if(x==y) printf("! B\n");
		else printf("! A\n");
	}
	fflush(stdout);
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
