#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=216,p=1e9+7;
int n,m;
string str;
ll f[kn][kn][kn];
int nxts[kn], pres[kn][2]; // pres[i][j]: i+1位与j不配, 换成什么长度才能配上j
void get_nxts(){
	int i=2,j=1;
	while(i<=m){
		if(str[i]==str[j]) nxts[i++]=j++;
		else if(j>1) j=nxts[j-1]+1;
		else nxts[i++]=0;
	}
}
void gen_pres(){
	for(int i=0;i<=m;++i){
		int cur=i;
		while(cur&&str[cur+1]!='(') cur=nxts[cur];
		pres[i][0]=cur+(str[cur+1]=='(');
		cur=i;
		while(cur&&str[cur+1]!=')') cur=nxts[cur];
		pres[i][1]=cur+(str[cur+1]==')');
	}
}
void upd(ll &cur,ll nxt){ cur=(cur+nxt)%p; }
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>str; n<<=1; m=str.size(); str=" "+str;
	get_nxts(); gen_pres();
	f[0][0][0]=1;
	for(int i=0;i<n;++i){
		// left brac
		for(int j=(i+1>>1);j<n;++j){
			for(int k=0;k<m;++k)
				upd( f[i+1][j+1][pres[k][0]] , f[i][j][k] );
			upd( f[i+1][j+1][m] , f[i][j][m] );
		}
		// right brac
		for(int j=(i+2>>1);j<n;++j){
			for(int k=0;k<m;++k)
				upd( f[i+1][j][pres[k][1]] , f[i][j][k] );
			upd( f[i+1][j][m] , f[i][j][m] );
		}
	}
	cout<<f[n][n>>1][m]<<endl;
	return 0;
}
/*
f[i][j][k]

填到第i个, 有j个左括号, 填到模式串第k位
*/
