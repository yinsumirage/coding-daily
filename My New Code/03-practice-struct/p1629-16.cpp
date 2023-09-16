#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=0x3f3f3f3f;
const int N = 1e3 + 5;

int n,m;
ll ans=0;
int head[N],cnt=0;
ll dis[N];

struct node{
    int v,w,nxt;
}e[N];

void add(int u,int v,int w){
    e[++cnt].v=v;
    e[cnt].w=w;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}

priority_queue<pii,vector<pii>,greater<pii>> q;

void dij(int s){
    for(int i=1;i<=n<<1;i++){
        dis[i]=INF;
    }
    dis[s]=0;
    q.push(make_pair(0,s));
    while(!q.empty()){
        pii u=q.top();q.pop();
        if(dis[u.second]<u.first)continue;
        // 
        for(int i=head[u.second];i;i=e[i].nxt){
            int v=e[i].v;
            int w=e[i].w;
            if(dis[v]>u.first+w){
                dis[v]=u.first+w;
                q.push(pii(dis[v],v));
            }
        }
    }
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
    n=read();m=read();
    for(int i=1;i<=m;i++){
        int u=read(),v=read(),w=read();
        add(u,v,w);add(v+n,u+n,w);
    }
    dij(1);
    for(int i=2;i<=n;i++)ans+=dis[i];
    dij(1+n);
    for(int i=2+n;i<=n<<1;i++)ans+=dis[i];
    printf("%lld\n",ans);
    system("pause");
}