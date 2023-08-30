#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e2 + 5;

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

void add(int x,int y){
    e[++tot].to=y;
    e[tot].nxt=head[x];
    head[x]=tot;
}

int dfn[N],low[N],dcnt,sk[N],insk[N],top;
int scc[N],sc;
int siz[N];

void tarjan(int u){
    low[u]=dfn[u]=++dcnt;
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
        while(sk[top]!=u){
            scc[sk[top]]=sc;
            siz[sc]++;
            insk[sk[top]]=0;
            --top;
        }
        scc[sk[top]]=sc;
        siz[sc]++;
        insk[sk[top]]=0;
        --top;
    }
}

int n,m,cn=0;
string a,b;
map<string ,int > ma;
string nam[N];

signed main() {
    //fastio;
    n=read();
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        nam[++cn]=a,ma[a]=cn;
        nam[++cn]=b,ma[b]=cn;
        add(cn-1,cn);
    }
    m=read();
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        add(ma[b],ma[a]);
    }
    for(int i=1;i<=cn;i++){
        if(!dfn[i])tarjan(i);
    }
    for(int i=1;i<=2*n;i+=2){
        if(scc[i]!=scc[i+1])printf("Safe\n");
        else printf("Unsafe\n");
    }
    system("pause");
}