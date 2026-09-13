#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=1e5+15;
int n,pre[kn];
class SGT{
	public:
	char t[kn<<5];
	int ls[kn<<5],rs[kn<<5],rt[kn],tot=0;
	void pushup(int cur){
		if(!ls[cur]||!t[ls[cur]]) return;
		if(!rs[cur]||!t[rs[cur]]) return;
		t[cur]='*';
	}
	void input(int &cur,int l,int r,char w){
		t[++tot]=t[cur];
		ls[tot]=ls[cur];
		rs[tot]=rs[cur];
		cur=tot;
		if(l==r){
			t[cur]=w;
			return;
		}
		int mid=(l+r)>>1;
		if(!ls[cur]||!t[ls[cur]])
			input(ls[cur],l,mid,w);
		else
			input(rs[cur],mid+1,r,w);
		pushup(cur);
	}
	char query(int cur,int l,int r,int x){
		if(!cur)
			return '*';
		if(l==r){
			return t[cur];
		}
		int mid=(l+r)>>1;
		if(x<=mid)
			return query(ls[cur],l,mid,x);
		else
			return query(rs[cur],mid+1,r,x);
		return '*';
	}
}sgt;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1,cur=0,cnt=0;i<=n;++i){
		char ch;
		cin>>ch;
		if(ch=='T'){
			char w;
			cin>>w;
			pre[++cnt]=cur;
			sgt.input(sgt.rt[cnt]=sgt.rt[cur],1,n,w);
			cur=cnt;
		}
		else if(ch=='U'){
			int x;
			cin>>x;
			pre[++cnt]=cur;
			while(x--){
				cur=pre[cur];
			}
			sgt.rt[cnt]=sgt.rt[cur];
			cur=cnt;
		}
		else{
			int x;
			cin>>x;
			cout<<sgt.query(sgt.rt[cur],1,n,x)<<'\n';
		}
	}
	return 0;
}
