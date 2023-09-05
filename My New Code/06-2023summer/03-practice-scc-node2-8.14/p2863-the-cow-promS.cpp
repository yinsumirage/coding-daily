#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 5e4 + 5;

int n,m,ans;

struct edge{
    int nxt,to;
}e[N];

int head[N],tot;

void add(int u,int v){
    e[++tot].to=v;
    e[tot].nxt=head[u];
    head[u]=tot;
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
            scc[sk[top]]++;
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

signed main() {
    //fastio;
    n=read();
    m=read();
    for(int i=1,a,b;i<=m;i++){
        a=read(),b=read();
        add(a,b);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])tarjan(i);
    }
    for(int i=1;i<=sc;i++){
        if(siz[i]>1)ans++;
    }
    printf("%d",ans);
    //system("pause");
}