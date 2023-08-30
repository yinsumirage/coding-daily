#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e3 + 5;

// scc 缩点
// 拓扑排序

int n,m;

int head[N],tot,headnew[N],totnew;
struct edge{
    int to,nxt,we;
}e[N],newe[N];

void add(int u,int v,int w){
    e[++tot].to=v;
    e[tot].nxt=head[u];
    e[tot].we=w;
    head[u]=tot;
}

void addnew(int u,int v,int w){
    newe[++totnew].to=v;
    newe[totnew].nxt=headnew[u];
    newe[totnew].we=w;
    headnew[u]=totnew;
}

int low[N],dfn[N],dfncnt,sk[N],top;
bool insk[N];
int scc[N],sc,siz[N];

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
            siz[sc]++;
            top--;
        }while(sk[top+1]!=u);
    }
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

int in[N],dp[N];
ll ans=0;

signed main() {
    //fastio;
    n=read();
    m=read();
    for(int i=1;i<=m;i++){
        int x,a,b;
        x=read(),a=read(),b=read();
        if(x==1){
            add(a,b,0),add(b,a,0);
        }
        else if(x==2){
            add(a,b,1);
        }
        else if(x==3){
            add(b,a,0);
        }
        else if(x==4){
            add(b,a,1);
        }
        else{
            add(a,b,0);
        }
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])tarjan(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=head[i];j;j=e[j].nxt){
            int v=e[j].to;
            if(scc[v]==scc[i]&&e[j].we==1){
                printf("-1\n");
                return 0;
            }
            if(scc[v]!=scc[i]){
                addnew(scc[i],scc[v],e[j].we);
                in[scc[v]]++;
            }
        }
    }

    queue<int>q;
    for(int i=1;i<=sc;i++){
        if(!in[i]){
            q.push(i);dp[i]=1;
        }
    }
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=headnew[now];i;i=newe[i].nxt){
            int v=newe[i].to;
            in[v]--;
            dp[v]=max(dp[v],dp[now]+newe[i].we);
            if(!in[v])q.push(v);
        }
    }
    for(int i=1;i<=sc;i++){
        ans+=(ll)dp[i]*siz[i];
    }
    printf("%lld\n",ans);
    system("pause");
}