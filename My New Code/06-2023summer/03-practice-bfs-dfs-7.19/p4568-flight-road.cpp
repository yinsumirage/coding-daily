#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

int n,m,k,s,t;
int cnt=0,ans=1e9;
int head[N],dis[N],vis[N];

struct node{
    ll to,w,nxt;
}way[2500005];

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

void add(int u,int v,int w){
    way[++cnt].to=v;
    way[cnt].w=w;
    way[cnt].nxt=head[u];
    head[u]=cnt;
}

void dijkstra(){
    memset(dis,0x3f,sizeof(dis));//这里不能放到n，要全放最大
    dis[s]=0;
    //priority_queue<pair<int,int>> q;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    q.push({0,s});
    while(!q.empty()){
        pii p1=q.top();
        q.pop();
        int u=p1.second; //记录堆顶，最小的边，并弹出
        if(vis[u])continue;
        vis[u]=1;
        for(int i=head[u];i;i=way[i].nxt){
            int v=way[i].to;
            if(dis[v]>dis[u]+way[i].w){
                dis[v]=dis[u]+way[i].w;
                q.push({dis[v],v});
            }
        }
    }
}

signed main() {
    fastio;
    n=read();m=read();k=read();
    s=read();t=read();
    for(int i=0;i<m;i++){
        int a,b,c;
        a=read(),b=read(),c=read();
        add(a,b,c);add(b,a,c);
        for(int j=1;j<=k;j++){
            add(a+(j-1)*n,b+j*n,0);//向下连接
            add(b+(j-1)*n,a+j*n,0);//新的一层全是0的边
            add(a+j*n,b+j*n,c);
            add(b+j*n,a+j*n,c);//把新的一层图上连上
        }
    }
    for(int i=1;i<=k;i++){
        add(t+(i-1)*n,t+i*n,0);
    }
    dijkstra();
    printf("%d\n",dis[t+k*n]);
    //system("pause");
}