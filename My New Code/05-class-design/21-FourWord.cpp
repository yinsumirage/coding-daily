#include<iostream>
#include<queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 5;

int m,a,b;
int st[4],ed[4],stp[N];
bool vis[N]={0};
queue<int> q;

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

int head[N],tot=0;

struct edge{
    int v,nxt;
}e[N];

void add(int u,int v){
    e[++tot].v=v;
    e[tot].nxt=head[u];
    head[u]=tot;
}

void bfs(int* sa,int* en){
    for(int i=0;i<N;i++)stp[i]=-1;
    vis[sa[3]]=1;stp[sa[3]]=1;
    q.push(sa[3]);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v;
            if(!vis[v]){
                q.push(v);vis[v]=1;
                stp[v]=stp[u]+1;
                if(u!=en[0]&&v==en[3]){
                    vis[v]=0;stp[v]--;
                }
            }
            if(u==en[0]&&v==en[3])break;
        }
    }
}

int main(){
    m=read();
    for(int i=0;i<m;i++){
        a=read();
        b=read(),b=read(),b=read();
        add(a,b);
    }
    for(int i=0;i<4;i++)st[i]=read();
    for(int i=0;i<4;i++)ed[i]=read();
    if(st[0]==ed[0]&&st[1]==ed[1]&&st[2]==ed[2]&&st[3]==ed[3]){
        printf("1\n");
        return 0;
    }
    bfs(st,ed);
    printf("%d\n",stp[ed[3]]);
    system("pause");
}