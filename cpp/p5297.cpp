#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using cit=const int&;
const int kn=56,km=kn*kn<<1;
int n,m,N;
char a[kn][kn];
vector<int> nbr[km]; // 真-假|
inline void set_or(cit i,cit x,cit j,cit y){
	nbr[i+x*N].emplace_back(j+!y*N);
	nbr[j+y*N].emplace_back(i+!x*N);
}
int dfn[km],low[km],scc[km],tot=0,sct=0;
bool ins[km];
stack<int> stk;
void tarjan(int cur){
	low[cur]=dfn[cur]=++tot;
	ins[cur]=true;
	stk.push(cur);
	for(auto nxt: nbr[cur]){
		if(!dfn[nxt]) tarjan(nxt), low[cur]=min(low[cur],low[nxt]);
		else if(ins[nxt]) low[cur]=min(low[cur],dfn[nxt]);
	}
	if(dfn[cur]==low[cur]){
		++sct;
		while(!stk.empty()){
			int nxt=stk.top(); stk.pop();
			ins[nxt]=false;
			scc[nxt]=sct;
			if(nxt==cur) break;
		}
	}
}
int idx[kn][kn],idt=0;
int dx[]={-1,0,1,0}, dy[]={0,1,0,-1}; // 上右下左
pii dfs(cit x,cit y,int fc){
	if(x<1||y<1||x>n||y>m||a[x][y]=='#') return make_pair(0,0);
	else if(idx[x][y]) return make_pair(idx[x][y],(fc==1||fc==3));
	else if(a[x][y]=='/') fc^=1;
	else if(a[x][y]=='\\') fc=3-fc;
	int nx=x+dx[fc], ny=y+dy[fc];
	return dfs(nx,ny,fc);
}
bool prep(){
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j){
		cin>>a[i][j];
		if(a[i][j]=='-'||a[i][j]=='|') idx[i][j]=++idt;
	}
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j){
		if(a[i][j]!='.'&&!idx[i][j]) continue;
		vector<int> de(6,0),fc(6,0);
		for(int k=0;k<4;++k){
			pii ret=dfs(i+dx[k],j+dy[k],k);
			de[k]=ret.first, fc[k]=ret.second;
		}
		if(a[i][j]=='.'){
			if(de[0]&&de[2]) set_or(de[0],fc[0]^1,de[0],fc[0]^1), set_or(de[2],fc[2]^1,de[2],fc[2]^1);
			else if(de[0]||de[2]) de[4]=de[0]|de[2], fc[4]=fc[0]|fc[2];
			if(de[1]&&de[3]) set_or(de[1],fc[1]^1,de[1],fc[1]^1), set_or(de[3],fc[3]^1,de[3],fc[3]^1);
			else if(de[1]||de[3]) de[5]=de[1]|de[3], fc[5]=fc[1]|fc[3];
			if(de[4]&&de[5]) set_or(de[4],fc[4],de[5],fc[5]);
			else if(de[4]||de[5]) set_or(de[4]|de[5],fc[4]|fc[5],de[4]|de[5],fc[4]|fc[5]);
			else return false;
		}
		else{
			if(de[0]||de[2]) set_or(idx[i][j],1,idx[i][j],1);
			if(de[1]||de[3]) set_or(idx[i][j],0,idx[i][j],0);
		}
	}
	return true;
}
void clear(){
	for(int i=1;i<=(N<<1);++i) nbr[i].clear();
	memset(dfn,0,sizeof(dfn));
	memset(idx,0,sizeof(idx));
	tot=sct=idt=0;
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int t; cin>>t;
	while(t--){
		cin>>n>>m; N=n*m;
		clear();
		if(!prep()){ cout<<"IMPOSSIBLE\n"; continue; }
		for(int i=1;i<=n;++i) for(int j=1;j<=m;++j){
			if(idx[i][j]&&!dfn[idx[i][j]]) tarjan(idx[i][j]);
			if(idx[i][j]&&!dfn[idx[i][j]+N]) tarjan(idx[i][j]+N);
		}
		bool flg=false;
		for(int i=1;i<=n;++i) for(int j=1;j<=m;++j){
			if(!idx[i][j]) continue;
			if(scc[idx[i][j]]<scc[idx[i][j]+N]) a[i][j]='-';
			else if(scc[idx[i][j]]>scc[idx[i][j]+N]) a[i][j]='|';
			else flg=true;
		}
		if(flg){ cout<<"IMPOSSIBLE\n"; continue; }
		else cout<<"POSSIBLE\n";
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j) cout<<a[i][j];
			cout<<'\n';
		}
	}
	return 0;
}
/*
debug logs:
1. There's laser from a direction doesn't mean it's started with the same direction.
2. Incorrect 2SAT template.
3. Bool return value in prep() is mistaken.
4. Two single guns will meet if there's no blank between them.
5. Arrays' sizes are too small.
6. One mirror and the start position can be passed twice
*/
