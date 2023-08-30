#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;


struct edge{
    int to,nxt;
}e[N<<2];
int head[N<<2],cnt;

void add(int u,int v){
    e[++cnt].to=v;
    e[cnt].nxt=head[u];
    head[u]=cnt;
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
//在遍历完与x相连的所有点，如果dfnx=lowx，直到弹出x
//弹出的点都在一个强连通分量里

