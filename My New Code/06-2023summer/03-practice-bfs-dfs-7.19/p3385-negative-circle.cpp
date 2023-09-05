#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;


int n,m,cnt=0,T;
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

void SPFA(int s){
    queue<int> q;
    memset(tot,0,sizeof(tot)); //记得归零
    memset(vis,0,sizeof(vis)); //每次循环都要重复用
    memset(dis,0x3f,sizeof(dis)); //!!!!!!!!!!!!!!memset 是一个字节的设置，不能写1e8会爆
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
                    if(++tot[v]>=n){
                        printf("YES\n");
                        return;
                    }
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    printf("NO\n");
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
    T=read();
    while(T--){
        n=read(),m=read();
        cnt=0;
        memset(head,0,sizeof(head));
        for(int i=1;i<=m;i++){
            int u,v,w;
            u=read(),v=read(),w=read();
            if(w>=0)add(v,u,w);
            add(u,v,w);
        }
        SPFA(1);
    }
    //system("pause");
}