#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=0x3f3f3f3f;
const int N = 5005;

int n,m,h,w[N],shi[N],have[N],eanub[N],tim[N];
int head[N],tot=0;

struct node{
    int nxt,to;
}e[N];

void add(int u,int v){
    e[++tot].to=v;
    e[tot].nxt=head[u];
    head[u]=tot;
}

void dfs(int now,int fa){
    int mt,mp;
    if(have[now]){
    }
    else {}
    for(int i=head[now];i;i=e[i].nxt){
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,now);
        if((tim[v]+1<mt)||(tim[v]+1==mt&&have[v]<mp)){
            mt=tim[v]+1;mp=have[v];
        }
    }
    tim[now]=mt;have[now]=mp;
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
    n=read();
    for(int i=1;i<n;i++){
        int a=read(),b=read();
        add(a,b),add(b,a);
    }
    m=read();
    for(int i=1;i<=m;i++){
        w[i]=read();
        have[w[i]]=i;
    }
    h=read();
    for(int i=1;i<=h;i++){
        shi[i]=read();
    }
    for(int i=1;i<h;i++){
        memset(tim,0,sizeof(tim));
        memset()
    }

    system("pause");
}