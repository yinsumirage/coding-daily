#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e4 + 5;

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

struct edge{
    int nxt,to;
}e[N],en[N];

int tot,head[N],ntot,nehead[N];

void add(int u,int v){
    e[++tot].to=v;
    e[tot].nxt=head[u];
    head[u]=tot;
}

void addnew(int u,int v){
    en[++ntot].to=v;
    en[ntot].nxt=nehead[u];
    nehead[u]=ntot;
}

int low[N],dfn[N],dfncnt,sk[N],top;
bool insk[N];
int scc[N],sc;

void tarjan(int u){
    low[u]=dfn[u]=++dfncnt;
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
    if(dfn[u]==low[u]){
        ++sc;
        do{
            scc[sk[top]]=sc;
            insk[sk[top]]=0;
            top--;
        }while(sk[top+1]!=u);
    }
}

int n,m,d;
int w[N],v[N],up[N];
int val[N],co[N];
bool usd[N];
int f[N][N];

void dfs(int u){
    for(int i=co[u];i<=m;i++)f[u][i]=val[u];
    for(int i=nehead[u];i;i=en[i].nxt){
        int v=en[i].to;
        dfs(v);
        for(int j=m-co[u];j>=0;j--){
            for(int q=0;q<=j;q++){
                f[u][j+co[u]]=max(f[u][j+co[u]],f[u][j+co[u]-q]+f[v][q]);
            }
        }
    }
}


signed main() {
    //fastio;
    n=read();
    m=read();
    for(int i=1;i<=n;i++)w[i]=read();
    for(int i=1;i<=n;i++)v[i]=read();
    for(int i=1;i<=n;i++){
        up[i]=read();
        if(up[i]!=0)add(up[i],i);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])tarjan(i);
    }
    for(int i=1;i<=n;i++){
        val[scc[i]]+=v[i];
        co[scc[i]]+=w[i];
        if(scc[i]!=scc[up[i]]&&up[i]!=0){ //缩完的点不同且相连
            addnew(scc[up[i]],scc[i]); //把缩后的点加进去
            usd[scc[i]]=1;
        }
    }
    int s=sc+1;
    for(int i=1;i<=sc;i++){
        if(!usd[i])addnew(s,i);
    }
    co[s]=0;
    val[s]=0;
    dfs(s);
    printf("%d\n",f[s][m+co[s]]);
    //system("pause");
}