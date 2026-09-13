#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=1e3+13;
int n,a[kn],idx[kn];
inline void _swap(int x){
	swap(a[x],a[x+1]);
	swap(idx[x],idx[x+1]);
	printf("swap %d\n",x);
	fflush(stdout);
}
inline int _throw(int x){
	printf("throw %d\n",x);
	fflush(stdout);
	int res=0; cin>>res;
	return res;
}
inline void _solv(){
	cin>>n;
	for(int i=1;i<=n+1;++i){ a[i]=0; idx[i]=i; }
	for(int i=n-1;i>=1;i-=2){
		int op=0,x=0,y=0,sum=0;
		for(int j=i+2;j<=n;){
			if(a[j]==1&&a[j+1]==2&&!op){ op=1; }
			else if(a[j]==2&&a[j+1]==1&&!op){ op=2; }
			j+=a[j];
			++sum;
		}
		if(!op){ op=(i==n-1||a[n-1]==2 ? 2 : 1); }
		if(op==2){
			x=_throw(i);
			_swap(i);
			y=_throw(i);
			if(x==y){ a[i]=a[i+1]=(x-1==sum ? 2 : 1); }
			else{
				if(x-1==sum){ a[i]=1; a[i+1]=2; }
				else{ a[i]=2; a[i+1]=1; }
			}
		}
		else{
			x=_throw(i+1);
			_swap(i);
			y=_throw(i+1);
			if(x==y){ a[i]=a[i+1]=(x-1==sum ? 1 : 2); }
			else{
				if(x-1==sum){ a[i]=1; a[i+1]=2; }
				else{ a[i]=2; a[i+1]=1; }
			}
		}
//		for(int j=1;j<=n;++j){ printf("%d ",a[j]); } printf("\n");
//		for(int j=1;j<=n;++j){ printf("%d ",idx[j]); } printf("\n");
	}
	if(n&1){
		int sum=0,op=0;
		for(int j=2;j<=n;){
			if(a[j]==2&&a[j+1]==1&&!op){ _swap(j); op=1; }
			else if(a[j]==1&&a[j+1]==2&&!op){ op=1; }
			j+=a[j];
			++sum;
		}
		if(!op&&a[n-1]==2){
			_swap(1);
			int x=_throw(2);
			a[2]=(x-1==sum ? 1 : 2);
		}
		else{
			int x=_throw(1);
			a[1]=(x-1==sum ? 1 : 2);
		}
	}
	printf("! ");
	vector<int> ans(n+1);
	for(int i=1;i<=n;++i){ ans[idx[i]]=a[i]; }
	for(int i=1;i<=n;++i){ printf("%d ",ans[i]); }
	printf("\n");
	fflush(stdout);
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T; while(T--) _solv();
	return 0;
}
