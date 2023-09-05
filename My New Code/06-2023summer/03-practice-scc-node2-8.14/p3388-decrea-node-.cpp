#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

int n,m,ans,root,cutnode[N];

struct edge{
    int to,nxt;
}e[N];

int head[N],tot;

void add(int u,int v){
    e[++tot].to=v;
    e[tot].nxt=head[u];
    head[u]=tot;
}

int dfn[N],low[N],dfncnt;

//找割点

void tarjan(int u){
    int child=0;
    dfn[u]=low[u]=++dfncnt;
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].to;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
            if(u==root)child++;
            if(dfn[u]<=low[v]&&u!=root)cutnode[u]=1;
        }
        else {
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(u==root&&child>1)cutnode[u]=1;
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
        int u=read(),v=read();
        add(u,v),add(v,u);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])root=i,tarjan(i);
    }
    for(int i=1;i<=n;i++){
        if(cutnode[i])ans++;
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++){
        if(cutnode[i])printf("%d ",i);
    }
    system("pause");
}