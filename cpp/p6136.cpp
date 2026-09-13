#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kN=1145141;
namespace SPL{

int rot,tot,val[kN],fa[kN],ch[kN][2],siz[kN],cnt[kN];
inline void pushup(int cur){ if(cur) siz[cur]=siz[ch[cur][0]]+siz[ch[cur][1]]+cnt[cur]; }
inline bool isson(int cur){ return (ch[fa[cur]][1]==cur); }
inline void cnct(int x,int y,bool op){ ch[x][op]=y; fa[y]=x; }
inline void rotate(int x){
	int y=fa[x], z=fa[y]; bool op=isson(x);
	cnct(z,x,isson(y));
	cnct(y,ch[x][!op],op);
	cnct(x,y,!op);
	pushup(y);
}
inline void splay(int cur){
	for(int ff=fa[cur]; ff; rotate(cur),ff=fa[cur])
		if(fa[ff]) rotate(isson(ff)==isson(cur) ? ff : cur);
	pushup(cur);
	rot=cur;
}
inline void ins(int v){
	if(!rot) { val[rot=++tot]=v; cnt[rot]=1; pushup(rot); return; }
	int cur=rot, pre=0;
	while(true){
		if(!cur){ val[cur=++tot]=v; cnt[cur]=1; cnct(pre,cur,(v>val[pre])); break; }
		else if(v==val[cur]){ cnt[cur]++; break; }
		pre=cur; cur=ch[cur][v>val[cur]];
	}
	pushup(cur); pushup(pre); splay(cur);
}
inline int findR(){ return siz[ch[rot][0]]+1; }
inline int findV(int r){
	int cur=rot;
	while((siz[ch[cur][0]]<r && siz[ch[cur][0]]+cnt[cur]>=r) == false)
		if(siz[ch[cur][0]]>=r) cur=ch[cur][0];
		else r-=siz[ch[cur][0]]+cnt[cur], cur=ch[cur][1];
	splay(cur);
	return val[cur];
}
inline int findP(){
	int cur=ch[rot][0];
	if(!cur) return 0;
	while(ch[cur][1]) cur=ch[cur][1];
	splay(cur);
	return val[cur];
}
inline int findS(){
	int cur=ch[rot][1];
	if(!cur) return 0;
	while(ch[cur][0]) cur=ch[cur][0];
	splay(cur);
	return val[cur];
}
inline void del(int v){
	ins(v);
	int cur=rot;
	if(cnt[cur]>2) cnt[cur]-=2;
	else if(!ch[cur][0]) rot=ch[cur][1], cnct(0,ch[cur][1],0);
	else if(!ch[cur][1]) rot=ch[cur][0], cnct(0,ch[cur][0],0);
	else findP(), cnct(rot,ch[cur][1],1);
	pushup(rot);
}

}
int n,m;
signed main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){ int x; scanf("%d",&x); SPL::ins(x); }
	int ret=0;
	for(int i=1,lst=0;i<=m;i++){
		int op,x,ans=0; scanf("%d %d",&op,&x);
		x^=lst;
		switch(op){
			case 1: SPL::ins(x); break;
			case 2: SPL::del(x); break;
			case 3: SPL::ins(x); ans=SPL::findR(); SPL::del(x); break;
			case 4: ans=SPL::findV(x); break;
			case 5: SPL::ins(x); ans=SPL::findP(); SPL::del(x); break;
			case 6: SPL::ins(x); ans=SPL::findS(); SPL::del(x); break;
		}
		if(3<=op && op<=6){
			ret^=ans;
			lst=ans;
		}
	}
	printf("%d\n",ret);
	return 0;
}
