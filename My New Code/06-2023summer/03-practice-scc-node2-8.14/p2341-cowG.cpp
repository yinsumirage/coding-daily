#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e6 + 5;


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

int tot,head[N<<2];

struct edge{
    int nxt,to;
}e[N<<2];

void add(int u,int v){
    e[++tot].to=v;
    e[tot].nxt=head[u];
    head[u]=tot;
}

int dfn[N],low[N],sk[N];
bool insk[N];
int dfncnt,cnt,top;
int scc[N],sc,siz[N];

void tarjan(int u){
    dfn[u]=low[u]=++dfncnt;
    sk[++top]=u;insk[u]=1;
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
        ++sc;
        while(sk[top]!=u){
            scc[sk[top]]=sc;
            siz[sc]++;
            insk[sk[top]]=0;
            top--;
        }
        scc[sk[top]]=sc;
        insk[sk[top]]=0;
        siz[sc]++;
        top--;
    }
}

int n,m,jishu[N],ans,k;

signed main() {
    //fastio;
    n=read();
    m=read();
    for(int i=0;i<m;i++){
        int x=read(),y=read();
        add(y,x);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])tarjan(i);
    }
    for(int w=1;w<=n;w++){
        for(int i=head[w];i;i=e[i].nxt){
            int v=e[i].to;
            if(scc[v]!=scc[w]){
                jishu[scc[v]]++;
            }
        }
    }
    for(int i=1;i<=sc;i++){
        if(!jishu[i])ans=siz[i],k++;
    }
    if(k==1)printf("%d",ans);
    else printf("0");
    //system("pause");
}