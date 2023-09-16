#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=0x3f3f3f3f;
const int N = 4e3 + 5;

int n,m,x;
int head[N],cnt=1;
int dis[N];
ll ans=0,tmp=0;

// 网络最大流的模板 地震逃生
// 要点 cnt=1 后面同时赋两个值的时候 ^1的时候才能正常

struct node{
    int v,nxt;
    ll w;
}e[N];

void add(int u,int v,ll w){
    e[++cnt].v=v;
    e[cnt].w=w;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}

bool bfs(){
    queue<int>q;
    memset(dis,0,sizeof(dis));
    q.push(1);dis[1]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v;
            if(!dis[v]&&e[i].w){
                q.push(v);
                dis[v]=dis[u]+1;
                if(v==n)return 1;
            }
        }
    }
    return 0;
}

ll dfs(int u,ll flow){
    if(u==n)return flow;
    ll res=flow;
    for(int i=head[u];i&&res;i=e[i].nxt){
        int v=e[i].v;
        if(e[i].w&&dis[v]==dis[u]+1){
            ll tmp=dfs(v,min(res,e[i].w));
            if(!tmp)dis[v]=0; //剪枝，将不能增广的点去了
            res-=tmp;e[i].w-=tmp;e[i^1].w+=tmp;
        }
    }
    return flow-res;
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
    n=read();m=read();x=read();
    for(int i=1;i<=m;i++){
        int a=read(),b=read();
        ll c=read();
        add(a,b,c);
        add(b,a,0);
    }
    while(bfs()){
        while(tmp=dfs(1,1e9))ans+=tmp;
    }
    if(!ans){
        printf("Orz Ni Jinan Saint Cow!");
        return 0;
    }
    printf("%d %d\n",ans,(x-1)/ans+1);
    system("pause");
}