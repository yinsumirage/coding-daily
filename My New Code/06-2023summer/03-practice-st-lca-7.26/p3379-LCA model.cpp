#include <bits/stdc++.h>
#include<ext/rope>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;

int a,b;
int n,m,s;
int head[N],cnt,dep[N],dp[N][21];

struct edge{
    int v,nxt;
}e[N*2];

void add(int u,int v){
    e[++cnt].v=v;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}

void dfs(int root,int fa){
    dep[root]=dep[fa]+1;
    dp[root][0]=fa;//2的0次方 向上一个
    for(int i=1;(1<<i)<=dep[root];i++){  //对该节点进行预处理
        dp[root][i]=dp[dp[root][i-1]][i-1];
    }
    for(int j=head[root];j;j=e[j].nxt){  //遍历他每一个子节点
        int v=e[j].v;
        if(v!=fa)dfs(v,root);
    }
}

int lca(int x,int y){
    if(dep[x]>dep[y])swap(x,y);//保证y更深一些
    for(int i=20;i>=0;i--){
        if(dep[x]<=dep[y]-(1<<i))y=dp[y][i];
    } //使得深度一样
    if(x==y)return x;
    for(int i=20;i>=0;i--){
        if(dp[x][i]==dp[y][i])continue;
        else x=dp[x][i],y=dp[y][i];
    }
    return dp[x][0];
}

ll read(){
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
    n=read();m=read();s=read();
    for(int i=1;i<=n-1;i++){
        int x,y;
        x=read(),y=read();
        add(x,y),add(y,x);
    }
    dfs(s,0);
    for(int i=1;i<=m;i++){
        a=read(),b=read();
        printf("%d\n",lca(a,b));
    }
    //system("pause");
}
