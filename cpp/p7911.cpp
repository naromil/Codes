#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
vector<int> proc_addr(const string &ad){
	vector<int> ret;
	int dots=0,maos=0,upd=0;
	for(int j=0;j<ad.size();++j){
		if(ad[j]=='.') ++dots, upd=0;
		else if(ad[j]==':') ++maos, upd=0;
		else{
			upd=10*upd+(ad[j]-'0');
			if(j==ad.size()-1){ if(upd<=65535) ret.emplace_back(upd); else goto _fail; }
			else if(ad[j+1]=='.' || ad[j+1]==':'){ if(upd<=255) ret.emplace_back(upd); else goto _fail; }
		}
		if(ad[j]==':'&&dots!=3) goto _fail;
		if(dots>3||maos>1||upd>65535) goto _fail;
		if(j<ad.size()-1 && upd==0 && ad[j]=='0' && ad[j+1]>='0' && ad[j+1]<='9') goto _fail;
		if(j>1 && (ad[j]=='.'||ad[j]==':') && (ad[j-1]=='.'||ad[j-1]==':')) goto _fail;
	}
	if(dots!=3 || maos!=1 || ret.size()!=5) goto _fail;
	return ret;
	_fail:
	vector<int> tmp(1,-1);
	return tmp;
}
map<vector<int>,int> svs;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i){
		string op,ad;
		cin>>op>>ad;
		vector<int> addr=proc_addr(ad);
		if(addr[0]==-1) cout<<"ERR\n";
		else if(op=="Server"){
			if(!svs[addr]) svs[addr]=i, cout<<"OK\n";
			else cout<<"FAIL\n";
		}
		else{
			if(svs[addr]) cout<<svs[addr]<<'\n';
			else cout<<"FAIL\n";
		}
	}
	return 0;
}
