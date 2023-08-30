#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int maxm = 1e6 + 5;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;

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
struct Edge
{
    int u,v,w,next;
}e[maxm];
int head[maxn],cnt,n,m,s,vis[maxn],dis[maxn],coun[maxn];
int mod=100003;
struct node
{
    int w,now;
    inline bool operator <(const node &x)const
    {
        return w>x.w;
    }
};
priority_queue<node>q;
inline void add(int u,int v,int w)
{
    e[++cnt].u=u;
    e[cnt].v=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    head[u]=cnt;
}
void dijkstra()
{
    for(int i=1;i<=n;i++)
    {
        dis[i]=INF;
    }
    dis[s]=0;
    q.push((node){0,s});
    while(!q.empty())
    {
        node x=q.top();
        q.pop();
        int u=x.now;
        if(vis[u]) continue; 
        vis[u]=1;
        for(int i=head[u];i;i=e[i].next)
        {
            int v=e[i].v;
            if(dis[v]==dis[u]+e[i].w){
                coun[v]=(coun[v]+coun[u])%mod;
            }
            else if(dis[v]>dis[u]+e[i].w){
            	dis[v]=dis[u]+e[i].w;
                coun[v]=coun[u];
            	q.push((node){dis[v],v});
            }
        }
    }
}

signed main() {
    fastio;
    n=read();m=read();
    s=1;
    coun[1]=1;
    for(int i=1,u,v;i<=m;i++){
        u=read();v=read();
        add(u,v,1);
        add(v,u,1);
    }
    dijkstra();
    for(int i=1;i<=n;i++){
        printf("%d\n",coun[i]%mod);
    }
    //system("pause");
}