#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=4e4+44;
char dict[62];
int pos[128];
void init(){
	for(int i=0;i<10;++i) dict[i]=i+'0', pos[i+'0']=i;
	for(int i=0;i<26;++i) dict[i+10]=i+'a', pos[i+'a']=i+10;
	for(int i=0;i<26;++i) dict[i+36]=i+'A', pos[i+'A']=i+36;
}
string str;
string solve1(){
	int sum=0;
	stack<char> stk;
	for(int i=str.size()-1;i>=0;--i){
		int cc=str[i]-'a';
	}
}
signed main(){
	init();
	string op; cin>>op>>str;
	cout<<(op=="COMPRESS" ? solve1() : solve2())<<'\n';
	return 0;
}
