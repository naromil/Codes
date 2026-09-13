#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=1e6+16;
int n,mc[kn];
char a[kn];
class SUC{ public: char val; int sw1=0,sw2=0; };
SUC make_suc(const char &x,const int &y,const int &z){ return (SUC){x,y,z}; }
void prep(){
	scanf("%s",&a[1]); n=strlen(&a[1]);
	stack<int> stk;
	for(int i=1;i<=n;++i)
		if(a[i]=='(') stk.push(i);
		else if(a[i]==')') mc[stk.top()]=i, mc[i]=stk.top(), stk.pop();
}
SUC calc(const int &l,const int &r){
	list<SUC> ls;
	for(int i=l;i<=r;++i){
		if(a[i]=='(') ls.emplace_back(calc(i+1,mc[i]-1)), i=mc[i];
		else ls.emplace_back(make_suc(a[i],0,0));
	}
	for(auto it=ls.begin();it!=ls.end();){
		if((*it).val=='&'){
			auto pr=it,sf=it; --pr; ++sf;
			SUC nxt=make_suc(((*pr).val-'0'&(*sf).val-'0')+'0',(*pr).sw1,(*pr).sw2);
			if((*pr).val=='0') ++nxt.sw1;
			else nxt.sw1+=(*sf).sw1, nxt.sw2+=(*sf).sw2;
			ls.erase(pr++); ls.erase(pr++); ls.erase(pr++);
			ls.emplace(it=pr,nxt);
		}
		else ++it;
	}
	for(auto it=ls.begin();it!=ls.end();){
		if((*it).val=='|'){
			auto pr=it,sf=it; --pr; ++sf;
			SUC nxt=make_suc(((*pr).val-'0'|(*sf).val-'0')+'0',(*pr).sw1,(*pr).sw2);
			if((*pr).val=='1') ++nxt.sw2;
			else nxt.sw1+=(*sf).sw1, nxt.sw2+=(*sf).sw2;
			ls.erase(pr++); ls.erase(pr++); ls.erase(pr++);
			ls.emplace(it=pr,nxt);
		}
		else ++it;
	}
	return *(ls.begin());
}
signed main(){
	prep();
	SUC ret=calc(1,n);
	printf("%c\n%d %d\n",ret.val,ret.sw1,ret.sw2);
	return 0;
}
