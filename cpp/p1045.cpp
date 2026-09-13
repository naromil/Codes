#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int dg=1e8;
class SINT{
	public:
	int m[128],len;
	void operator = (const int &nxt){
		memset(m,0,sizeof(m));
		m[len=1]=nxt;
	}
	SINT operator * (const SINT &nxt){
		SINT ret; ret=0;
		for(int i=1;i<=len;++i){
			int upd=0;
			for(int j=1;j<=nxt.len;++j){
				ll cur=ret.m[i+j-1] + upd + 1ll*m[i]*nxt.m[j];
				ret.m[i+j-1]=cur%dg;
				upd=cur/dg;
			}
			ret.m[i+nxt.len]=upd;
		}
		ret.len=min(63,len+nxt.len-(!ret.m[len+nxt.len]));
		return ret;
	}
}cur,bs;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int n; cin>>n;
	cout<<(int)(log10(2)*n+1)<<'\n';
	cur=1; bs=2;
	while(n){
		if(n&1) cur=cur*bs;
		bs=bs*bs;
		n>>=1;
	}
	--cur.m[1];
	stack<int> stk;
	for(int i=0;i<500;++i){
		int k=i/8+1;
		stk.push(cur.m[k]%10);
		cur.m[k]/=10;
	}
	for(int i=1;i<=500;++i){
		cout<<stk.top();
		stk.pop();
		if(i%50==0) cout<<'\n';
	}
	return 0;
}
