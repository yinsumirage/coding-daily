#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=0x3f3f3f3f;
const int N = 1e5 + 5;

int n,m;
int col[5050];
int dp[N][2];
// dp 第i号节点 染成第j种颜色的最小花费
// 对于j号结点是它的儿子 可以染其为异色 也可以一致

int head[N],cnt=0;

struct node{
    int to,nxt;
}e[N];

void add(int u,int v){
    e[++cnt].to=v;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}

void dfs(int u,int fa){
    dp[u][0]=dp[u][1]=1;
    if(u<=n){
        if(col[u])dp[u][0]=INF;
        else dp[u][1]=INF;
    }
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].to;
        if(v!=fa){
            dfs(v,u);
            // 如果父亲结点已经染成x色 他想染x色可以不要染色 直接继承
            // 要染成x色 继承父亲染成x的代价 
            dp[u][0]+=min(dp[v][0]-1,dp[v][1]);
            dp[u][1]+=min(dp[v][0],dp[v][1]-1);
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

signed main() {
    m=read();
    n=read();
    for(int i=1;i<=n;i++)col[i]=read();
    for(int i=1;i<m;i++){
        int u=read(),v=read();
        add(u,v);add(v,u);
    }
    printf("");
    dfs(n+1,-1);
    printf("%d\n",min(dp[n+1][0],dp[n+1][1]));
    system("pause");
}