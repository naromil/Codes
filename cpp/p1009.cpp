#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=56,p=100000000;
int n;
class SINT{
	public:
	int len=0,m[50];
	SINT(int cur=0){
		memset(m,0,sizeof m);
		m[len=1]=cur;
	}
	void operator *= (const int &nxt){
		int upd=0;
		for(int i=1;i<=len;++i){
			ll cur=1ll*m[i]*nxt+upd;
			m[i]=cur%p;
			upd=cur/p;
		}
		if(upd) m[++len]=upd;
	}
	void operator += (const SINT &nxt){
		int upd=0;
		len=max(len,nxt.len);
		for(int i=1;i<=len;++i){
			ll cur=1ll*m[i]+nxt.m[i]+upd;
			m[i]=cur%p;
			upd=cur/p;
		}
		if(upd) m[++len]=upd;
	}
	void print(){
		printf("%d",m[len]);
		for(int i=len-1;i>=1;--i) printf("%08d",m[i]);
	}
};
signed main(){
	scanf("%d",&n);
	SINT ans(0),sum(1);
	for(int i=1;i<=n;++i){
		sum*=i;
		ans+=sum;
	}
	ans.print();
	return 0;
}
