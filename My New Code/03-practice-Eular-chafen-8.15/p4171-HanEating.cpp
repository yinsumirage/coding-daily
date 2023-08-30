#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 4e4 + 5;

// 2-sat

int k,n,m;

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

void clear(){
    for(int i=1;i<=n*2;i++){
        scc[i]=low[i]=dfn[i]=0;
    }
    for(int i=1;i<=2*m;i++){
        e[i].nxt=0;
        e[i].to=0;
    }
    memset(head,0,sizeof(head));
    cnt=dfncnt=top=sc=0;
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

char s1[10],s2[10];
int x,y;


signed main() {
    //fastio;
    k=read();
    while(k--){
        n=read(),m=read();
        for(int i=1;i<=m;i++){
            scanf("%s%s",&s1,&s2);
            x=0,y=0;
            for(int j=1;j<strlen(s1);j++){
                x=x*10+s1[j]-'0';
            }
            for(int j=1;j<strlen(s2);j++){
                y=y*10+s2[j]-'0';
            }
            if(s1[0]=='m'&&s2[0]=='m'){
                add(x+n,y);
                add(y+n,x);
            }
            else if(s1[0]=='m'&&s2[0]=='h'){
                add(x+n,y+n);
                add(y,x);
            }
            else if(s1[0]=='h'&&s2[0]=='m'){
                add(x,y);
                add(y+n,x+n);
            }
            else {
                add(x,y+n);
                add(y,x+n);
            }
        }
        for(int i=1;i<=n*2;i++){
            if(!dfn[i])tarjan(i);
        }
        bool judge=1;
        for(int i=1;i<=n;i++){
            if(scc[i]==scc[i+n]){
                printf("BAD\n");
                judge=0;
                break;
            }
        }
        if(judge)printf("GOOD\n");
        clear();
    }
    system("pause");
}