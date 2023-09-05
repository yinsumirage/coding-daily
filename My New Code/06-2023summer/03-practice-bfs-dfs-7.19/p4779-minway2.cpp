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
int head[maxn],cnt,n,m,s,vis[maxn],dis[maxn];
struct node
{
    int w,now;
    inline bool operator <(const node &x)const
    //重载运算符把最小的元素放在堆顶（大根堆）
    {
        return w>x.w;//这里注意符号要为'>'
    }
};
priority_queue<node>q;
//优先队列，其实这里一般使用一个pair，但为了方便理解所以用的结构体
inline void add(int u,int v,int w)
{
    e[++cnt].u=u;
    //这句话对于此题不需要，但在缩点之类的问题还是有用的
    e[cnt].v=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    //存储该点的下一条边
    head[u]=cnt;
    //更新目前该点的最后一条边（就是这一条边）
}
void dijkstra()
{
    for(int i=1;i<=n;i++)
    {
        dis[i]=INF;
    }
    dis[s]=0;
    //赋初值
    q.push((node){0,s});
    while(!q.empty())
    //堆为空即为所有点都更新
    {
        node x=q.top();
        q.pop();
        int u=x.now;
        //记录堆顶（堆内最小的边）并将其弹出
        if(vis[u]) continue; 
        //没有遍历过才需要遍历
        vis[u]=1;
        for(int i=head[u];i;i=e[i].next)
        //搜索堆顶所有连边
        {
            int v=e[i].v;
            if(dis[v]>dis[u]+e[i].w)
            {
            	dis[v]=dis[u]+e[i].w;
            	//松弛操作
            	q.push((node){dis[v],v});
            	//把新遍历到的点加入堆中
            }
        }
    }
}

signed main() {
    fastio;
    n=read();m=read();s=read();
    for(int i=1,u,v,w;i<=m;i++){
        u=read();v=read();w=read();
        add(u,v,w);
    }
    dijkstra();
    for(int i=1;i<=n;i++){
        printf("%d ",dis[i]);
    }
    //system("pause");
}