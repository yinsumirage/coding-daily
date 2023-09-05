#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e6 + 5;
const int INF=0x7f7f7f7f;

int n,m,t;

struct edge{
    int nxt,to,op;
    double we;
}e[N<<2];

int head[N],tot;

void add(int u,int v,double w,int op){
    e[++tot].to=v;
    e[tot].nxt=head[u];
    e[tot].we=w;
    e[tot].op=op;
    head[u]=tot;
}

double dis[N<<2];
int cnt[N<<2];
bool vis[N<<2];

bool spfa(double t){
    for(int i=0;i<=n;i++){
        dis[i]=-INF;
        cnt[i]=0;
        vis[i]=0;
    }
    dis[n+1]=0;
    queue<int>q;
    q.push(n+1);
    vis[n+1]=1;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        vis[now]=0;
        for(int i=head[now];i;i=e[i].nxt){
            int v=e[i].to;
            double w=e[i].we;
            if(e[i].op==1)w=log2(w-t);
            if(e[i].op==2)w=-log2(w+t);
            if(dis[v]<dis[now]+w){
                dis[v]=dis[now]+w;
                cnt[v]=cnt[now]+1;
                if(cnt[v]>=n+2)return true;
                else if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    return false; //有解
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

int a,b,k,op,c;
double r=10,ans,l=0,mid,x,cha=1e-5;

signed main() {
    //fastio;
    n=read();
    m=read();
    t=read();
    for(int i=0;i<=n;i++){
        add(n+1,i,0,3);
    }
    for(int i=1;i<=m;i++){
        op=read();a=read();b=read();k=read();
        add(b,a,k,op);
        if(op==1)r=fmin(r,k);
    }
    for(int i=1;i<=t;i++){
        c=read();x=read();
        add(0,c,log2(x),3);
        add(c,0,-log2(x),3);
    }
    if(!spfa(0))printf("-1\n");
    else {
        while(r-l>cha){
            mid=(l+r)/2.0;
            if(spfa(mid)){
                ans=mid;
                l=mid+cha;
            }
            else r=mid-cha;
        }
        printf("%.6lf\n",ans);
    }
    system("pause");
}