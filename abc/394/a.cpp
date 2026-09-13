#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string str;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>str;
	int sum=0;
	for(int i=0;i<str.size();++i){
		if(str[i]=='2') ++sum;
	}
	while(sum--) printf("2");
	printf("\n");
	return 0;
}
