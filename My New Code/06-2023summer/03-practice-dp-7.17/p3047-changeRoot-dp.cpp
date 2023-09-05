#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 5;
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
//f[i][j]表示到i的距离为j的奶牛有多少只

struct road{
    int to,next;;
} way[N*2];

int head[N],cnt=0;
int val[N];
int n,k;
ll f[N][22],d[N][22];
//f表示从上往下 d计算出总体的 表示i点动j步的权值和
//f[u][j]即是本身权值+子节点的f[v][j-1]
//d[u][i]+=d[x][i-1]-f[u][i-2] 就是把x向下中u的部分删去了

void add(int x,int y){
    way[++cnt].to=y;
    way[cnt].next=head[x];
    head[x]=cnt;
}

void dfs(int x,int fa){
    for(int i=0;i<=k;i++)f[x][i]=val[x];
    for(int i=head[x];i;i=way[i].next){ //这个遍历方式也要记住
        int u=way[i].to;
        if(u!=fa){
            dfs(u,x);
            for(int i=1;i<=k;i++){
                f[x][i]+=f[u][i-1];
            }
        }
    }
}

void dfs2(int x,int fa){
    for(int i=head[x];i;i=way[i].next){
        int u=way[i].to;
        if(u!=fa){
            d[u][1]+=f[x][0];  //补全向上这个方式的
            for(int i=2;i<=k;i++){
                d[u][i]+=d[x][i-1]-f[u][i-2]; //容斥原理
            }
            dfs2(u,x);
        }
    }
}


int main() {
    fastio;
    n=read();k=read();
    for(int i=1,x,y;i<n;i++){
        x=read();
        y=read();
        add(x,y);
        add(y,x);
    }
    for(int i=1;i<=n;i++){
        val[i]=read();
    }
    dfs(1,1);
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            d[i][j]=f[i][j];
        }
    }
    dfs2(1,1);
    for(int i=1;i<=n;i++){
        printf("%lld\n",d[i][k]);
    }

    return 0;
}