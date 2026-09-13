#include<bits/stdc++.h>
using namespace std;
using ll=long long;
unordered_map<string,int> siz;
unordered_map<string,unordered_map<int,int>> tp;
string shrink(const string &str){
	int lts=0;
	string ans="";
	for(int i=0;i<str.size();++i){
		if(str[i]=='['&&!ans.empty()&&ans.back()==' ') ans.pop_back();
		if(str[i]==' '&&(lts||!i||str[i-1]==' ')) continue;
		else if(str[i]=='[') ++lts;
		else if(str[i]==']') --lts;
		ans+=str[i];
	}
	while(!ans.empty()&&(ans.back()==' '||ans.back()=='\n'||ans.back()=='\r')) ans.pop_back();
	return ans;
}
int calc(const string &str,const int &L,const int &R){
	int lt=str.find('[',L);
	if(lt==str.npos||lt>R){ // only numbers remain
		int upd=0;
		for(int i=L;i<=R;++i) upd=10*upd+str[i]-'0';
		return upd;
	}
	else{
		string cnm="";
		for(int i=L;i<lt;++i) cnm+=str[i];
		int pos=calc(str,lt+1,R-1);
		if(pos>=siz[cnm]){ cout<<"-1\n"; exit(0); }
		return tp[cnm][pos];
	}
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	string str;
	while(getline(cin,str)){
		if(str=="exit") return 0;
		str=shrink(str);
		int mid=str.find(' ');
		if(str[mid-1]=='t'&&str[0]=='i'){
			string cnm="";
			for(int i=mid+1;i<str.size();++i){
				if(str[i]!='[') cnm+=str[i];
				else{ siz[cnm]=calc(str,i+1,str.size()-2); break; }
			}
		}
		else if(str[mid-1]=='t'&&str[0]=='c'){
			cout<<calc(str,mid+1,str.size()-1)<<'\n';
		}
		else{
			string cnm="";
			for(int i=0;i<str.size();++i){
				if(str[i]!='[') cnm+=str[i];
				else{
					int pos=calc(str,i+1,str.rfind(']',mid-1)-1);
					if(pos>=siz[cnm]){ cout<<"-1\n"; exit(0); }
					tp[cnm][pos]=calc(str,mid+1,str.size()-1);
					break;
				}
			}
		}
	}
	return 0;
}
