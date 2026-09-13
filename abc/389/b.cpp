#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,sum=1;
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;;++i){
		sum=sum*i;
		if(sum==n){
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}
