#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string s1,s2;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>s1>>s2;
	if(s1=="fine"&&s2=="fine") printf("4\n");
	else if(s1=="sick"&&s2=="fine") printf("2\n");
	else if(s1=="fine"&&s2=="sick") printf("3\n");
	else printf("1\n");
	return 0;
}
