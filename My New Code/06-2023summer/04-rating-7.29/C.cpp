#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define fu(i,j,k) for(i=j;i<=k;++i)
#define fd(i,j,k) for(i=j;i>=k;--i)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

int i,j,l,r;
ll n,m;
ll ans=0x3f3f3f3f;

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

inline ll read(){
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
    fastio;
    n=read();
    m=read();
    for(int i=0;i<n-1;i++){
        int u,v;
        u=read(),v=read();
        add(u,v);
        add(v,u);
    }
    dfs(1,0);
    while(m--){
        int x,y,z;
        x=read(),y=read(),z=read();
        int w1=lca(x,y),w2=lca(y,z),w3=lca(z,x),len;
        if(w1==w2==w3){
            len=dep[x]+dep[y]+dep[z]-3*dep[w1];
            printf("%d %d\n",w1,len);
        }
        else if(w1==w2){
            len=dep[x]+dep[z]+dep[y]-dep[w3]-2*dep[w1];
            printf("%d %d\n",w3,len);
        }
        else if(w1==w3){
            len=dep[x]+dep[y]+dep[z]-dep[w2]-2*dep[w1];
            printf("%d %d\n",w2,len);
        }
        else if(w2==w3){
            len=dep[x]+dep[y]+dep[z]-dep[w1]-2*dep[w3];
            printf("%d %d\n",w1,len);
        }
    }
    //system("pause");
}