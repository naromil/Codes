#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=108;
int m,n,p;
string nms[kn],wkd[]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
unordered_map<string,int> tn;
class SAID{
	public:
	bool dat=false,inv=false;
	int cur,nxt;
};
vector<SAID> qs;
void check(const string& str){
	string wd[7]; wd[1]=wd[2]=wd[3]=wd[4]=""; int pos=1;
	for(int i=0;i<str.size();++i){
		if(str[i]==' ' && ++pos>5) return;
		else if(str[i]!=' ') wd[pos]+=str[i];
	}
	if(pos<4 || wd[1].back()!=':' || wd[pos].back()!='.') return;
	wd[1].pop_back(), wd[pos].pop_back();
//	cerr<<"\n"; for(int i=1;i<=pos;++i) cerr<<"\""<<wd[i]<<"\"\n";
	if(!tn[wd[1]]) return;

	else if(pos==4 && wd[2]=="Today" && wd[3]=="is")
		for(int i=0;i<7;++i){ if(wd[4]==wkd[i]) qs.push_back({ true,false,tn[wd[1]],i }); }

	else if(pos==4 && wd[2]=="I" && wd[3]=="am" && wd[4]=="guilty")
		qs.push_back({ false,false,tn[wd[1]],tn[wd[1]] });
	else if(pos==5 && wd[2]=="I" && wd[3]=="am" && wd[4]=="not" && wd[5]=="guilty")
		qs.push_back({ false,true,tn[wd[1]],tn[wd[1]] });

	else if(!tn[wd[2]]) return;
	else if(pos==4 && wd[3]=="is" && wd[4]=="guilty")
		qs.push_back({ false,false,tn[wd[1]],tn[wd[2]] });
	else if(pos==5 && wd[3]=="is" && wd[4]=="not" && wd[5]=="guilty")
		qs.push_back({ false,true,tn[wd[1]],tn[wd[2]] });
}
void prep(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>m>>n>>p;
	for(int i=1;i<=m;++i) cin>>nms[i], tn[nms[i]]=i;
	string tmp; getline(cin,tmp);
	for(int i=1;i<=p;++i){
		string str; getline(cin,str);
		while(!str.empty()&&(str.back()=='\r'||str.back()=='\n')) str.pop_back();
		check(str);
	}
}

int vis[kn];
bool solve(int gui,int dat){
	memset(vis,-1,sizeof(vis));
	for(auto ntr: qs){
		int cur=ntr.cur;
		bool istr=false;
		if(ntr.dat && ntr.nxt==dat) istr=true;
		else if(!ntr.dat && (ntr.inv ^ ntr.nxt==gui)) istr=true;
		if(vis[cur]==-1) vis[cur]=istr;
		else if(vis[cur]!=istr) return false;
	}
	int cnt=0,blk=0;
	for(int i=1;i<=m;++i) cnt+=(vis[i]==0), blk+=(vis[i]==-1);
	return (cnt<=n && cnt+blk>=n);
}
signed main(){
	prep();
//	for(auto ntr: tn) cerr<<ntr.first<<' '<<ntr.second<<'\n';
//	cerr<<"==================\n";
//	for(auto ntr: qs) cerr<<ntr.date<<' '<<ntr.inv<<' '<<ntr.cur<<' '<<ntr.nxt<<'\n';

	int ans=0;
	for(int i=1;i<=m;++i){
		bool flg=false;
		for(int j=0;j<7;++j) if(solve(i,j)){ flg=true; break; }
		if(flg&&!ans) ans=i;
		else if(flg) ans=-1;
	}
	if(ans==0) cout<<"Impossible\n";
	else if(ans==-1) cout<<"Cannot Determine\n";
	else cout<<nms[ans]<<'\n';
	return 0;
}
