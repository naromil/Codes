#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e6+26;
ll n,N,sum=0;
inline double dist(const double& x,const double& y){ return x*x+y*y; }
inline bool chk(int x,int y){
	return (dist(x+0.5,y+0.5)<=N && dist(x+0.5,y-0.5)<=N && dist(x-0.5,y+0.5)<=N && dist(x-0.5,y-0.5)<=N);
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n;
	N=n*n;
//	if(n==1){ printf("1\n"); return 0; }
	int x=0,y=0;
	while(chk(x,y)) --x;
	if(!chk(x,y)) ++x;
	for(;x<0;++x){
		while(chk(x,y)) ++y;
		if(!chk(x,y)) --y;
		sum+=y+1;
	}
	printf("%lld\n",(sum<<2)+1);
	return 0;
}
