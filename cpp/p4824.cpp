#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kN=1e6+23;
int n,m,nxts[kN];
string str,pat;
void get_nxts(){
	int i=2,j=1;
	nxts[1]=0;
	while(i<=m){
		if(pat[i]==pat[j]) nxts[i++]=j++;
		else if(j>1) j=nxts[j-1]+1;
		else nxts[i++]=0;
	}
}
void prep(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>str>>pat;
	n=str.size(); str=" "+str;
	m=pat.size(); pat=" "+pat;
	get_nxts();
}
stack<pair<int,int>> stk;
void kmp(){
	int i=1,j=1;
	while(i<=n){
		if(str[i]==pat[j]) stk.push({ ++j,i++ });
		else if(j>1) j=nxts[j-1]+1;
		else stk.push({ j,i++ });
		if(j>m){
			for(int k=1;k<=m;k++) stk.pop();
			j=(!stk.empty()?stk.top().first:1);
		}
	}
}
signed main(){
	prep();
	kmp();
	vector<char> ans;
	while(!stk.empty()){
		ans.push_back(str[stk.top().second]);
		stk.pop();
	}
	reverse(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++) cout<<ans[i];
	return 0;
}
