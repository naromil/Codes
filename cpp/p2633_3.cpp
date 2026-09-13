#include<bits/stdc++.h>
using namespace std;
const int maxn=114514,L=1,R=100000;
int n,q,rt[maxn],a[maxn],dep[maxn],fa[maxn][20],mp[maxn];
pair<int,int>b[maxn];
class node{
    public:
    int v,ls,rs;
}t[maxn*36];
int tot=0;
vector<int>nbr[maxn];
inline void pushup(int cur){
    t[cur].v=t[t[cur].ls].v+t[t[cur].rs].v;
}
inline void update(int &cur,int l,int r,int pos){
    t[++tot]=t[cur];
    cur=tot;
    if(l==r){
        t[cur].v++;
        return;
    }
    int m=(1ll*l+r)>>1;
    if(pos<=m)
        update(t[cur].ls,l,m,pos);
    else
        update(t[cur].rs,m+1,r,pos);
    pushup(cur);
}
inline int query(int L,int R,int A,int B,int l,int r,int k){
    if(l==r)
        return l;
    int ls=t[t[R].ls].v+t[t[L].ls].v-t[t[A].ls].v-t[t[B].ls].v;
    int m=(1ll*l+r)>>1;
    if(ls>=k)
        return query(t[L].ls,t[R].ls,t[A].ls,t[B].ls,l,m,k);
    else
        return query(t[L].rs,t[R].rs,t[A].rs,t[B].rs,m+1,r,k-ls);
}
inline void dfs(int cur,int pre){
    dep[cur]=dep[pre]+1;
    rt[cur]=rt[pre];
    update(rt[cur],L,R,a[cur]);
    fa[cur][0]=pre;
    for(int i=1;i<=20;i++)
        fa[cur][i]=fa[fa[cur][i-1]][i-1];
    for(int i=0;i<nbr[cur].size();i++){
        int nxt=nbr[cur][i];
        if(nxt==pre)
            continue;
        dfs(nxt,cur);
    }
}
inline int lca(int x,int y){
    if(dep[x]<dep[y])
        swap(x,y);
    for(int i=20;i>=0;i--)
        if(dep[fa[x][i]]>=dep[y])
            x=fa[x][i];
    if(x==y)
        return y;
    for(int i=20;i>=0;i--)
        if(fa[x][i]!=fa[y][i])
            x=fa[x][i],
            y=fa[y][i];
    return fa[y][0];
}
signed main(){
    // ios::sync_with_stdio(false);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        b[i].second=i;
        cin>>b[i].first;
        // cin>>a[i];
    }
    sort(b+1,b+n+1);
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(b[i].first!=b[i-1].first)
            cnt++;
        a[b[i].second]=cnt;
        mp[cnt]=b[i].first;
    }
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        nbr[x].push_back(y);
        nbr[y].push_back(x);
    }
    dfs(1,0);
    int lst=0;
    for(int i=1;i<=q;i++){
        int l,r,g,k;
        cin>>l>>r>>k;
        l^=lst;
        g=lca(l,r);
        lst=mp[query(rt[l],rt[r],rt[g],rt[fa[g][0]],L,R,k)];
        cout<<lst<<'\n';
    }
    return 0;
}
/*
Logs:
1.取m时l+r越界
2.
*/
