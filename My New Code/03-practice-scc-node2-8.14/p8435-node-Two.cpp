#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 5e5 + 5;
const int M = 4e6+5;

int n,m,root;
vector<int>ans[N];

struct edge{
    int to,nxt;
}e[M];

int head[N],tot;

void add(int u,int v){
    e[++tot].to=v;
    e[tot].nxt=head[u];
    head[u]=tot;
}

int dfn[N],low[N],dfncnt;
int sk[N],top,sc;

void tarjan(int u){
    int child=0;
    dfn[u]=low[u]=++dfncnt;
    sk[++top]=u;
    if(u==root&&head[u]==0){
        ans[++sc].push_back(u);
        return;
    }
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].to;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]){
                child++;
                sc++;
                while(sk[top+1]!=v)ans[sc].push_back(sk[top--]);
                ans[sc].push_back(u);
            }
        }
        else {
            low[u]=min(low[u],dfn[v]);
        }
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

signed main(){
    //fastio;
    n=read();
    m=read();
    for(int i=1;i<=m;i++){
        int u=read(),v=read();
        if(u==v)continue;
        add(u,v),add(v,u);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])root=i,tarjan(i);
    }
    printf("%d\n",sc);
    for(int i=1;i<=sc;i++){
        printf("%d ",ans[i].size());
        for(int j:ans[i])printf("%d ",j);
        printf("\n");
    }
    system("pause");
}