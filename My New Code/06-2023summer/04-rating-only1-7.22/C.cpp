#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int maxm = 1e3 + 5;
const int maxn = 1e2 + 5;

ll n,m,na,nb;
ll ans=0x3f3f3f3f;
ll a[10005],b[10005];

struct Edge{
    ll u,v,w,next;
}e[maxm];

ll head[maxn],cnt,vis[maxn],dis[maxn];

struct node{
    ll w,now;
    inline bool operator <(const node &x)const{
        return w>x.w;//这里注意符号要为'>'
    }
};

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

priority_queue<node>q;
inline void add(int u,int v,int w)
{
    e[++cnt].u=u;
    e[cnt].v=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    head[u]=cnt;
}
void dijkstra(int x){
    for(int i=1;i<=n+2;i++){
        dis[i]=0x3f3f3f3f;
    }
    dis[x]=0;
    q.push((node){0,x});
    while(!q.empty()){
        node x=q.top();
        q.pop();
        int u=x.now;
        if(vis[u]) continue; 
        vis[u]=1;
        for(int i=head[u];i;i=e[i].next){
            int v=e[i].v;
            if(dis[v]>dis[u]+e[i].w){
            	dis[v]=dis[u]+e[i].w;
            	q.push((node){dis[v],v});
            }
        }
    }
}

signed main() {
    fastio;
    n=read();m=read();
    for(int i=1,u,v,w;i<=m;i++){
        u=read();v=read();w=read();
        add(u,v,w);
        add(v,u,w);
    }
    na=read();nb=read();
    for(int i=1;i<=na;i++){
        a[i]=read();
        add(n+1,a[i],0);
    }
    for(int i=1;i<=nb;i++){
        b[i]=read();
        add(b[i],n+2,0);
    }
    dijkstra(n+1);
    ans=dis[n+2];
    printf("%lld",ans);
    //system("pause");
}