#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=0x3f3f3f3f;
const int N = 1e6 + 5;

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

int n,m,ans=0,sum=0;

int cnt,head[N];
bool vis[N];

struct node{
    int nxt,to,we;
}e[N];

void add(int u,int v,int w){
    e[++cnt].to=v;
    e[cnt].nxt=head[u];
    e[cnt].we=w;
    head[u]=cnt;
}

void dfs(int u){
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].to;
        if(!vis[v]){
            vis[v]=1;
            ans+=e[i].we;
            sum=max(sum,ans);
            dfs(v);
            ans-=e[i].we;
            vis[v]=0;
        }
    }
}



signed main() {
    //fastio;
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=m;i++){
        int a=read(),b=read(),c=read();
        add(a,b,c);add(b,a,c);
    }
    for(int i=1;i<=n;i++){
        vis[i]=1;
        dfs(i);
        vis[i]=0;
    }
    printf("%d\n",sum);

    system("pause");
}