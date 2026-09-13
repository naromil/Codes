#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kN=1e5+23;
int tot,rot;
class SPLY{
	public:
	int val,cnt,siz,ch[2],fa;
}t[kN];
inline bool isson(int x){
	return (t[t[x].fa].ch[1]==x);
}
inline void clear(int cur){
	t[cur].ch[0]=t[cur].ch[1]=t[cur].fa=t[cur].val=t[cur].siz=t[cur].cnt=0;
}
inline void pushup(int cur){
	if(!cur) return;
	t[cur].siz=t[t[cur].ch[0]].siz+t[t[cur].ch[1]].siz+t[cur].cnt;
}
inline void rotate(int x){
	int y=t[x].fa, z=t[y].fa;
	bool op=isson(x);
	t[y].ch[op]=t[x].ch[!op];
	if(t[y].ch[op]) t[t[y].ch[op]].fa=y;
	t[x].ch[!op]=y;
	t[y].fa=x;
	t[x].fa=z;
	if(z) t[z].ch[y==t[z].ch[1]]=x;
	pushup(y);
	pushup(x);
}
inline void spaly(int x,int y){
	for(int f=t[x].fa; f=t[x].fa, f!=y; rotate(x))
		if(t[f].fa) rotate(isson(x)==isson(f)?f:x);
	rot=x;
}
inline void _insert(int val){
	int *cur=&rot, pre=0;
	while(true){
		if(!(*cur)){
			cur=&++tot;
			t[tot].val=val;
			t[tot].cnt++;
			t[tot].fa=pre;
			pushup(tot);
			t[pre].ch[val>t[pre].val]=tot, pushup(pre);
			spaly(*cur,0);
			return;
		}
		else if(t[*cur].val==val){
			t[*cur].cnt++;
			pushup(*cur);
			pushup(pre);
			spaly(*cur,0);
			return;
		}
		pre=*cur, cur=&t[*cur].ch[val>t[*cur].val];
	}
}
inline int findR(int val){
	int ret=0, cur=rot, pre=0;
	while(true){
		if(!cur){
			spaly(pre,0);
			return ret+1;
		}
		else if(val<t[cur].val)
			pre=cur, cur=t[cur].ch[0];
		else{
			ret+=t[t[cur].ch[0]].siz;
			if(val==t[cur].val){
				spaly(cur,0);
				return ret+1;
			}
			ret+=t[cur].cnt;
			pre=cur, cur=t[cur].ch[1];
		}
	}
}
inline int findV(int rnk){
	int cur=rot;
	while(true){
		int siz=t[t[cur].ch[0]].siz;
		if(t[cur].ch[0] && rnk<=siz)
			cur=t[cur].ch[0];
		else{
			rnk-=t[cur].cnt+siz;
			if(rnk<=0){
				spaly(cur,0);
				return t[cur].val;
			}
			cur=t[cur].ch[1];
		}
	}
}
inline int findP(){
	int cur=t[rot].ch[0];
	if(!cur) return cur;
	while(t[cur].ch[1]) cur=t[cur].ch[1];
	spaly(cur,0);
	return cur;
}
inline int findS(){
	int cur=t[rot].ch[1];
	if(!cur) return cur;
	while(t[cur].ch[0]) cur=t[cur].ch[0];
	spaly(cur,0);
	return cur;
}
inline void _delete(int val){
	findR(val);
	int cur=rot;
	if(t[cur].val!=val) return;
	else if(t[cur].cnt>1){
		t[cur].cnt--;
		pushup(cur);
	}
	else if(!t[cur].ch[0]){
		t[t[cur].ch[1]].fa=0;
		rot=t[cur].ch[1];
		clear(cur);
	}
	else{
		int pr=findP();
	}
}
//inline void _delete(int val){
//	findR(val);
//	if(t[rot].cnt>1){
//		t[rot].cnt--;
//		pushup(rot);
//	}
//	else if(!t[rot].ch[0]&&!t[rot].ch[1]){
//		clear(rot);
//		rot=0;
//	}
//	else if(!t[rot].ch[0]){
//		int cur=rot;
//		rot=t[rot].ch[1];
//		t[rot].fa=0;
//		clear(cur);
//	}
//	else if(!t[rot].ch[1]){
//		int cur=rot;
//		rot=t[rot].ch[0];
//		t[rot].fa=0;
//		clear(cur);
//	}
//	else{
//		int cur=rot, pr=findP();
//		t[t[cur].ch[1]].fa=pr;
//		t[pr].ch[1]=t[cur].ch[1];
//		clear(cur);
//		pushup(rot);
//	}
//}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int q; cin>>q;
	for(int i=1;i<=q;i++){
		int op,x; cin>>op>>x;
		switch(op){
			case 1: _insert(x); break;
			case 2: _delete(x); break;
			case 3: cout<<findR(x)<<'\n'; break;
			case 4: cout<<findV(x)<<'\n'; break;
			case 5: _insert(x); cout<<t[findP()].val<<'\n'; _delete(x); break;
			case 6: _insert(x); cout<<t[findS()].val<<'\n'; _delete(x); break;
		}
	}
	return 0;
}
