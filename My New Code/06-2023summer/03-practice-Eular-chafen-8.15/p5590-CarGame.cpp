#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 2e3+5;
const int INF=0x7f7f7f7f;

int n,m;

int head[N],tot,headnew[N],totnew;
struct edge{
    int to,nxt,we;
}e[N],newe[N];

void add(int u,int v){
    e[++tot].to=v;
    e[tot].nxt=head[u];
    head[u]=tot;
}

void addnew(int u,int v,int w){
    newe[++totnew].to=v;
    newe[totnew].nxt=headnew[u];
    newe[totnew].we=w;
    headnew[u]=totnew;
}

double dis[N<<2];
int cnt[N<<2];
bool vis[N<<2];

bool spfa(){
    for(int i=0;i<=n;i++){
        dis[i]=INF;
        cnt[i]=0;
        vis[i]=0;
    }
    queue<int>q;
    q.push(0);
    dis[0]=0;
    vis[0]=1;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        vis[now]=0;
        for(int i=headnew[now];i;i=newe[i].nxt){
            int v=newe[i].to, w=newe[i].we;
            if(dis[v]>dis[now]+w){
                dis[v]=dis[now]+w;
                cnt[v]=cnt[now]+1;
                if(cnt[v]>n)return 1;
                else if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    return 0; //有解
}

int p[N];

bool dfs(int x){
    if(x==n||p[x]){ //到n节点以及剪枝
        return 1;
    }
    for(int i=head[x];i;i=e[i].nxt){
        if(!vis[i]){
            int v=e[i].to;
            vis[i]=1;
            if(dfs(v)){ //能够到达
                addnew(x,v,9);
                addnew(v,x,-1);
                p[x]=1;
            }
        }
    }
    return p[x];
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

int x[N],y[N];

signed main() {
    //fastio;
    n=read();m=read();
    for(int i=1;i<=m;i++){
        x[i]=read();
        y[i]=read();
        add(x[i],y[i]);
    }
    for(int i=0;i<=n;i++){
        addnew(0,i,0);
    }
    if(!dfs(1)||spfa()){
        printf("-1\n");
        return 0;
    }
    printf("%d %d\n",n,m);
    for(int i=1;i<=m;i++){
        printf("%d %d ",x[i],y[i]);
        int now=abs(dis[x[i]]-dis[y[i]]);
        if(now>0&&now<10)printf("%d\n",now);
        else printf("1\n");
    }
    system("pause");
}