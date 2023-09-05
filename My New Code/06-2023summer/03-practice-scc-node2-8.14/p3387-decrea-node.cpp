#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

int n,m,x[N],y[N];
int a[N],sum[N];
int f[N];
int ans=0;

// 缩点获得最大的点权和

struct edge{
    int to,nxt;
}e[N],E[N];

int head[N],tot;
int Head[N],Tot;

void add(int u,int v){
    e[++tot].to=v;
    e[tot].nxt=head[u];
    head[u]=tot;
}

void Add(int u,int v){
    E[++Tot].to=v;
    E[Tot].nxt=Head[u];
    Head[u]=Tot;
}

int dfn[N],low[N],dfncnt;
int sk[N],top;
bool insk[N];
int scc[N],sc;

void tarjan(int u){
    dfn[u]=low[u]=++dfncnt;
    sk[++top]=u;
    insk[u]=1;
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].to;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(insk[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u]){
        sc++;
        do{
            scc[sk[top]]=sc;
            insk[sk[top]]=0;
            sum[sc]+=a[sk[top]];
            top--;
        }while(sk[top+1]!=u);
    }
}

// int totq;
// void topo(){
//     queue<int> q;
//     int tot=0;
//     for(int i=1;i<=sc;i++){
//         if(!in[i])q.push(i);
//     }
//     while(!q.empty()){
//         int now=q.front();
//         q.pop();
//         ans[++totq]=now;//topo排出来的
//         for(int i=head[now];i;i=e[i].to){
//             in[i]--;
//             if(in[i]==0)q.push(i);
//         }
//     }
// }

void search(int u){
    if(f[u])return;
    f[u]=sum[u];
    int maxsum=0;
    for(int i=Head[u];i;i=E[i].nxt){
        int v=E[i].to;
        if(!f[v])search(v);
        maxsum=max(f[v],maxsum);
    }
    f[u]+=maxsum;
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
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=m;i++){
        x[i]=read(),y[i]=read();
        add(x[i],y[i]);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])tarjan(i);
    }
    for(int i=1;i<=m;i++){
        int xx=scc[x[i]],yy=scc[y[i]];
        if(xx!=yy)Add(xx,yy);
    }
    for(int i=1;i<=sc;i++){
        if(!f[i]){
            search(i);
            ans=max(ans,f[i]);
        }
    }
    printf("%d",ans);
    system("pause");
}