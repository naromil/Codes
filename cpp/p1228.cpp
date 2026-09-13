#include<bits/stdc++.h>
#define add_ans(x,y,c) ans.emplace_back((ANSR){x,y,c})
#define mul_build(a1,a2,a3,a4) build(x,y,k-1,a1),build(x,ymd,k-1,a2),build(xmd,y,k-1,a3),build(xmd,ymd,k-1,a4)
using namespace std;
using ll=long long;
int m,X,Y; // 左上 右上 左下 右下
class ANSR{ public: int x,y,c; }; vector<ANSR> ans;

void build(const int &x,const int &y,const int &k,int op){
	int xmd=x+(1<<k-1), ymd=y+(1<<k-1);
	if(k>1){
		if(op==0) mul_build(!(X<=xmd&&Y<=ymd)*4,!(X<=xmd&&Y>ymd)*3,!(X>xmd&&Y<=ymd)*2,!(X>xmd&&Y>ymd)*1);
		else if(op==1) mul_build(1,3,2,1);
		else if(op==2) mul_build(4,2,2,1);
		else if(op==3) mul_build(4,3,3,1);
		else if(op==4) mul_build(4,3,2,4);
	}
	if(!op) op=1+(Y>ymd)+2*(X>xmd);
	if(op==1) add_ans(xmd+1,ymd+1,op);
	else if(op==2) add_ans(xmd+1,ymd,op);
	else if(op==3) add_ans(xmd,ymd+1,op);
	else if(op==4) add_ans(xmd,ymd,op);
}
int mat[1048][1048];
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>m>>X>>Y;
	build(0,0,m,0);
	for(ANSR ntr: ans) cout<<ntr.x<<' '<<ntr.y<<' '<<ntr.c<<'\n';
	return 0;
}
