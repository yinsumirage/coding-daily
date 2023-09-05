#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 5;
const int INF = 0x3fffffff;

// 求解严格次小的树

struct bian{
    int x,y,z;
}b[N*2];
bool cmp(bian a,bian b){
    return a.z<b.z;
}

int n,m;
bool usd[2*N];
int head[N],cnt,pa[N][21];
int dep[N],maxx[N][21]; //到祖先路径上边权最大与次大的边
int minn[N][21];
int fa[N];
ll sum=0;

struct edge{
    int v,nxt,val;
}e[N*2];

void add(int u,int v,int w){
    e[++cnt].v=v;
    e[cnt].val=w;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}

void dfs(int x,int fa){
    dep[x]=dep[fa]+1;
    pa[x][0]=fa;
    minn[x][0]=-INF;
    for(int i=1;(i<<i)<=dep[x];i++){//倍增
        pa[x][i]=pa[pa[x][i-1]][i-1];
        int ma[4]={maxx[x][i-1],maxx[pa[x][i-1]][i-1],minn[x][i-1],minn[pa[x][i-1]][i-1]};
        sort(ma,ma+4);
        maxx[x][i]=ma[3];
        int p=2;
        while(p>=0&&ma[p]==ma[3])p--;
        if(p==-1)minn[x][i]=-INF;
        else minn[x][i]=ma[p];
    }
    for(int i=head[x];i;i=e[i].nxt){
        if(e[i].v!=fa){
            maxx[e[i].v][0]=e[i].val;
            dfs(e[i].v,x);
        }
    }
}

int lca(int x,int y){
    if(dep[x]>dep[y])swap(x,y);//保证y更深一些
    for(int i=20;i>=0;i--){
        if(dep[x]<=dep[pa[y][i]])y=pa[y][i];
    } //使得深度一样
    if(x==y)return x;
    for(int i=20;i>=0;i--){
        if(pa[x][i]==pa[y][i])continue;
        else x=pa[x][i],y=pa[y][i];
    }
    return pa[x][0];
}

int find(int x){
    if(fa[x]!=x)fa[x]=find(fa[x]);
    return fa[x];
}

int que(int x,int y,int w){
    int r=-INF;
    for(int i=20;i>=0;i--){
        if(dep[pa[x][i]] < dep[y])continue;
        else {
            if(w!=maxx[x][i])
                r=max(r,maxx[x][i]);
            else 
                r=max(r,minn[x][i]);
            x=pa[x][i];
        }
    }
    return r;
}

void kruskal(){
    int tot=0;
    sort(b+1,b+m+1,cmp);
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        if(find(b[i].x)!=find(b[i].y)){
            fa[find(b[i].x)]=find(b[i].y);
            tot++;
            add(b[i].x,b[i].y,b[i].z);
            add(b[i].y,b[i].x,b[i].z);
            sum+=b[i].z;
            usd[i]=1;
        }
        if(tot == n-1)break;
    }
}


inline ll read(){
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
    n=read();
    m=read();
    for(int i=1;i<=m;i++){
        b[i].x=read();
        b[i].y=read();
        b[i].z=read();
    }
    kruskal();
    ll ans=INF;
    dfs(1,0);
    for(int i=1;i<=m;i++){
        if(!usd[i]){
            int LCA=lca(b[i].x,b[i].y);
            ll ta=que(b[i].x,LCA,b[i].z);
            ll tb=que(b[i].y,LCA,b[i].z);
            if(max(ta,tb)>-INF)ans=min(ans,sum-max(ta,tb)+b[i].z);
        }
    }
    printf("%lld",ans);
    system("pause");
}