#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e4 + 5;

int n,m;

struct edge{
    int nxt,to;
}e[N];
int head[N],tot;

void add(int u,int v){
    e[++tot].to=v;
    e[tot].nxt=head[u];
    head[u]=tot;
}

int dfn[N],low[N],sk[N],top;
int dfncnt;
bool insk[N];
int sc,scc[N];

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

int cd[N],rd[N];
// 统计出度与入度
int Aans,Bans;

signed main() {
    //fastio;
    n=read();
    for(int i=1;i<=n;i++){
        int x;
        while(x=read()){
            add(i,x);
        }
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])tarjan(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=head[i];j;j=e[j].nxt){
            int v=e[j].to;
            if(scc[i]!=scc[v]){
                cd[scc[i]]++;
                rd[scc[v]]++;
            }
        }
    }
    for(int i=1;i<=sc;i++){
        if(rd[i]==0)Aans++;
        if(cd[i]==0)Bans++;
    }
    printf("%d\n",Aans);
    if(sc==1)printf("0");
    else printf("%d",max(Aans,Bans));
    //system("pause");
}