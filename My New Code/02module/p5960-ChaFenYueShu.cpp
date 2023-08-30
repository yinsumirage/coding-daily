#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

//差分约束
//spfa 判断负环
//特殊加边方法

int n,m,cnt=0;
int head[5005],tot[5005],dis[5005],vis[5005];

struct edge{
    int v,w,nxt;
}e[10005];

void add(int u,int v,int w){
    e[++cnt].v=v;
    e[cnt].w=w;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}

bool SPFA(int s){
    queue<int> q;
    memset(dis,63,sizeof(dis));
    dis[s]=0;
    vis[s]=1;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v;
            if(dis[v]>dis[u]+e[i].w){
                dis[v]=dis[u]+e[i].w;
                if(!vis[v]){
                    vis[v]=1;
                    tot[v]++; //访问一圈了，出负环寄了
                    if(tot[v]==n+1)return false;
                    q.push(v);
                }
            }
        }
    }
    return true;
}

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

signed main() {
    fastio;
    n=read();m=read();
    for(int i=1;i<=n;i++){
        add(0,i,0);
    }
    for(int i=1;i<=m;i++){
        int c,cc,y;
        c=read(),cc=read(),y=read();
        add(cc,c,y);//注意顺序问题，是从哪到哪
    }
    if(!SPFA(0))printf("NO\n");
    else {
        for(int i=1;i<=n;i++)printf("%d ",dis[i]);
    }
    //system("pause");
}