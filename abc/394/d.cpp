#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string a;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>a;
	stack<char> stk;
	for(int i=0;i<a.size();++i){
		if(a[i]=='<') stk.push('<');
		else if(a[i]=='[') stk.push('[');
		else if(a[i]=='(') stk.push('(');
		else if(a[i]=='>'&&!stk.empty()&&stk.top()=='<') stk.pop();
		else if(a[i]==']'&&!stk.empty()&&stk.top()=='[') stk.pop();
		else if(a[i]==')'&&!stk.empty()&&stk.top()=='(') stk.pop();
		else{ printf("No\n"); return 0; }
	}
	printf(stk.empty()?"Yes\n":"No\n");
	return 0;
}
