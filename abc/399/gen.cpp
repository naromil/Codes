#include<bits/stdc++.h>
using namespace std;
using ll=long long;
mt19937 mtrand(time(0));
inline int rng(int l,int r){ return mtrand()%(r-l+1)+l; }
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int n=rng(5,1000);
	printf("%d\n",n);
	string a=" ";
	for(int i=1;i<=n;++i){
		a+='a'+rng(0,25);
		printf("%c",a[i]);
	}
	printf("\n");
	string b=a;
	int t=rng(1,n>>1);
	while(t--){
		char ch=rng('a','z'),nx=rng('a','z');
		for(int i=1;i<=n;++i) if(b[i]==ch) b[i]=nx;
	}
	for(int i=1;i<=n;++i){
		printf("%c",b[i]);
	}
	printf("\n");
	return 0;
}
