#include<bits/stdc++.h>
#define pii pair<int,int>
#define x first
#define y second
#define mp make_pair
using namespace std;
using ll=long long;
const int kn=2e6+26;
int n,m;
string a;
pii dfs(int l,int r){
	if(l==r){ return mp(a[l]-'0',1); }
	int lm=(r-l+1)/3, rm=lm<<1;
	lm+=l-1; rm+=l-1;
	pii L=dfs(l,lm), M=dfs(lm+1,rm), R=dfs(rm+1,r), ret;
	if(L.x==M.x&&M.x==R.x){
		ret.x=L.x;
		ret.y=min({L.y+M.y, L.y+R.y, M.y+R.y});
	}
	else if(L.x==M.x){
		ret.x=L.x;
		ret.y=min(L.y, M.y);
	}
	else if(M.x==R.x){
		ret.x=M.x;
		ret.y=min(M.y, R.y);
	}
	else if(L.x==R.x){
		ret.x=L.x;
		ret.y=min(L.y, R.y);
	}
	return ret;
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>m>>a; n=a.size(); a=" "+a;
	printf("%d\n",dfs(1,n).y);
	return 0;
}
