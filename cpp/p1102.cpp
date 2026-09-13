#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,c;
pair<int,int> a[kn];
void prep(){
	static int b[kn],blc=0;
	scanf("%d %d",&n,&c);
	for(int i=1;i<=n;++i) scanf("%d",&b[i]);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;++i){
		if(i==1||b[i]!=b[i-1]) a[++blc].x=b[i];
		++a[blc].y;
	}
}
signed main(){
	prep();
	ll ret=0;
	for(int r=1,l=1;r<=n;++r){
		while(a[r].x-a[l].x>c) ++l;
		if(a[r].x-a[l].x==c) ret+=1ll*a[l].y*a[r].y;
	}
	cout<<ret<<'\n';
	return 0;
}
