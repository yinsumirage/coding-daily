#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 4e6 + 5;

int n,m,ans;

struct edge{
    int nxt,to;
}e[N],ed[N];

int head[N],tot,edhead[N],edtot;

void add(int u,int v){
    e[++tot].to=v;
    e[tot].nxt=head[u];
    head[u]=tot;
}

void added(int u,int v){
    ed[++edtot].to=v;
    ed[edtot].nxt=edhead[u];
    edhead[u]=edtot;
}

int dfn[N],low[N],dfncnt;
int sk[N],top;
bool insk[N];
int scc[N],sc,siz[N];

void tarjan(int u){
    dfn[u]=low[u]=++dfncnt;
    sk[++top]=u;
    insk[u]=1;
    for(int i=head[u];i;i=e[i].nxt){
        const int &v=e[i].to;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(insk[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u]){
        sc++;
        do{
            scc[sk[top]]=sc;
            insk[sk[top]]=0;
            siz[sc]++;
            top--;
        }while(sk[top+1]!=u);
    }
}

int dis[N],vis[N];

bool spfa(int s){
    queue<int> q;
    dis[s]=0;
    vis[s]=1;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=edhead[u];i;i=ed[i].nxt){
            int v=ed[i].to;
            if(dis[v]<dis[u]+siz[v]){
                dis[v]=dis[u]+siz[v];
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    return true;
}


inline ll read(){//read和cin不能同时处理字符
    ll x=0,f=1;
    char c=getchar();
    while(c>'9'||c<'0'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    }
    return x*f;
}

signed main() {
    //fastio;
    n=read();
    m=read();
    for(int i=1;i<=m;i++){
        int x=read(),y=read();
        add(x,y);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])tarjan(i);
    }
    for(int i=1;i<=sc;i++)siz[i+sc]=siz[i];
    for(int i=1;i<=n;i++){
        for(int j=head[i];j;j=e[j].nxt){
            int v=e[j].to;
            if(scc[i]!=scc[v]){
                added(scc[i],scc[v]);
                added(scc[v],scc[i]+sc);
                added(scc[i]+sc,scc[v]+sc);
            }
        }
    }
    spfa(scc[1]);
    printf("%d",dis[scc[1]+sc]);
    //system("pause");
}