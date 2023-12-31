#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=0x3f3f3f3f;
const int N = 1e4 + 5;

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

int n;
int w,u,v;
int pe[N],siz[N];
int head[N],tot=0;
ll ans=INF,dp[N];

struct way{
    int to,nxt;
}e[N];

void add(int u,int v){
    e[++tot].to=v;
    e[tot].nxt=head[u];
    head[u]=tot;
}

void dfs(int u,int fa,int dep){
    siz[u]=pe[u];
    for(int i=head[u];i;i=e[i].nxt){
        if(e[i].to!=fa){
            dfs(e[i].to,u,dep+1);
            siz[u]+=siz[e[i].to];
        }
    }
    dp[1]+=pe[u]*dep;
}

void DP(int u,int fa){
    for(int i=head[u];i;i=e[i].nxt){
        if(e[i].to!=fa){
            dp[e[i].to]=dp[u]+siz[1]-siz[e[i].to]*2;
            DP(e[i].to,u);
        }
    }
    ans=min(ans,dp[u]);
}

signed main() {
    //fastio;
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++){
        pe[i]=read();u=read();v=read();
        if(u)add(i,u),add(u,i);
        if(v)add(i,v),add(v,i);
    }
    dfs(1,0,0);DP(1,0);
    printf("%lld\n",ans);
    system("pause");
}