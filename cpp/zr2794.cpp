#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll=long long;
const int kN=1e5+23;
int n,m,a[kN],lg[kN];
ll sum[kN],st[kN][24],ts[kN][24];
int rp[kN],tnx[kN],tpr[kN];
ll chmax(ll x,ll y){ return (x>y)?x:y; }
ll chmin(ll x,ll y){ return (x<y)?x:y; }
int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
void prep(){
	n=readint(), m=readint();
	lg[1]=0; for(int i=2;i<=n+1;i++) lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++){
		st[i][0]=ts[i][0]=sum[i]=sum[i-1]+(a[i]=readint());
	}
	st[0][0]=ts[0][0]=0;
	for(int k=1;k<=lg[n+1];k++) for(int i=0;i+(1<<k)-1<=n;i++){
		st[i][k]=chmax(st[i][k-1], st[i+(1<<k-1)][k-1]);
		ts[i][k]=chmin(ts[i][k-1], ts[i+(1<<k-1)][k-1]);
	}
	for(int i=1;i<=n;i++) rp[i]=i, tnx[i]=i+1, tpr[i]=i-1;
	tnx[n+1]=n+1;
	sort(rp+1,rp+n+1,[](int x,int y){ return a[x]<a[y]; });

	if(m==0){
		ll ans=-1e18,ff=0;
		for(int i=1;i<=n;i++) ff=chmax(ff+a[i],1ll*a[i]), ans=chmax(ans,ff);
		printf("%lld\n",ans);
		exit(0);
	}
}
ll getmax(int l,int r){
	int len=lg[r-l+1];
	return chmax(st[l][len], st[r-(1<<len)+1][len]);
}
ll getmin(int l,int r){
	int len=lg[r-l+1];
	return chmin(ts[l][len], ts[r-(1<<len)+1][len]);
}
ll ans=-1e18;
signed main(){
	prep();
	static ll pre[kN];
	for(int ii=1;ii<=n;ii++){
		int i=rp[ii], lt=i, rt=i, len=1;
		ll cur=a[i];
		while(len<m && tpr[lt]!=0) cur += a[lt=tpr[lt]], len++;
		while(len<m && tnx[rt]!=n+1) cur += a[rt=tnx[rt]], len++;
		if(len==m) while(lt<=i && rt!=n+1){
			ans=chmax(ans, getmax(rt,tnx[rt]-1) - getmin(tpr[lt],lt-1) - cur);
			cur = cur - a[lt] + a[tnx[rt]];
			lt=tnx[lt], rt=tnx[rt];
		}
		tpr[tnx[i]]=tpr[i], tnx[tpr[i]]=tnx[i];
	}
	printf("%lld\n",ans);
	return 0;
}
