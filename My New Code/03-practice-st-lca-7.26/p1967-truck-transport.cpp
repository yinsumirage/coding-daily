#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define fup(i,j,k) for(i=j;i<=k;++i)
#define fdo(i,j,k) for(i=j;i>=k;--i)
typedef long long ll;
const int N = 50005;

// Kruskal构造最大生成树
// LCA找到答案

int i,j,l,r,q;
int n,m;
int head[N],cnt=0,dep[N],f[N];
int fa[N][21],w[N][21]; //20是log2(int)最大范围
//f数组是并查集的父节点 fa数组是树上的父节点 w表示最大载重
bool vis[N];

struct edge{
    int x,y,z;
}e[N*5]; //题目图

struct edge2{
    int v,nxt,w;
}e2[10*N];

void add(int u,int v,int w){
    e2[++cnt].v=v;
    e2[cnt].w=w;
    e2[cnt].nxt=head[u];
    head[u]=cnt;
}

bool cmp(edge x,edge y){
    return x.z>y.z; //将边权从大到小排序
}

int find(int x){ //并查集寻找父节点-代表元
    if(f[x]!=x)f[x]=find(f[x]);//用递归的方式将所有的点上级都设为根节点
    return f[x]; 
}

void kruskal(){
    sort(e+1,e+m+1,cmp);
    fup(i,1,n){
        f[i]=i;  //初始化并查集
    }
    fup(i,1,m){
        if(find(e[i].x)!=find(e[i].y)){
            f[find(e[i].x)]=find(e[i].y);
            add(e[i].x,e[i].y,e[i].z);
            add(e[i].y,e[i].x,e[i].z);
        }
    }
}

void dfs(int x){
    vis[x]=true;
    for(int i=head[x];i;i=e2[i].nxt){
        int v=e2[i].v;
        if(vis[v])continue;
        dep[v]=dep[x]+1; //计算深度
        fa[v][0]=x;      //储存父节点
        w[v][0]=e2[i].w; //储存到父节点的权值
        dfs(v);
    }
}

int lca(int x,int y){
    if(find(x)!=find(y))return -1;
    int ans=0x3f3f3f3f;
    if(dep[x]>dep[y])swap(x,y); //保证y节点深
    fdo(i,20,0){
        if(dep[fa[y][i]>=dep[x]]){
            ans=min(ans,w[y][i]); //更新最大载重（最小边权）
            y=fa[y][i];
        }
    }
    if(x==y)return ans; //位置相等直接返回答案
    fdo(i,20,0){
        if(fa[x][i]!=fa[y][i]){
            ans=min(ans,min(w[x][i],w[y][i]));
            x=fa[x][i];
            y=fa[y][i];//修改x,y位置
        }
    }
    ans=min(ans,min(w[x][0],w[y][0]));
    return ans;
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
    n=read(),m=read();
    fup(i,1,m){ //存题目给的图
        int x,y,z;
        x=read(),y=read(),z=read();
        e[i].x=x;
        e[i].y=y;
        e[i].z=z;
    }
    kruskal();
    fup(i,1,n){
        if(!vis[i]){
            dep[i]=1;
            dfs(i);
            fa[i][0]=i;
            w[i][0]=0x3f3f3f3f;
        }
    } //LCA初始化
    fup(i,1,20){
        fup(j,1,n){ //fa代表第i个节点向上走2^j步到达的节点
            fa[j][i]=fa[fa[j][i-1]][i-1];
            w[j][i]=min(w[j][i-1],w[fa[j][i-1]][i-1]);
        }
    }
    q=read();
    while(q--){
        int x,y;
        x=read(),y=read();
        printf("%d\n",lca(x,y));
    }
    //system("pause");
}


// AC代码
// #include<cstdio>  
// #include<algorithm>  
// #include<cstring>  
// #include<iostream>  
// #define MAXN 10005 
// #define INF 999999999
// using namespace std; 
// struct Edge1{  
//     int x,y,dis;
// }edge1[50005]; //题目所给的图 
// struct Edge2{
//     int to,next,w;
// }edge2[100005]; //最大生成树的图 
// int cnt,n,m,head[MAXN],deep[MAXN],f[MAXN],fa[MAXN][21],w[MAXN][21];
// //f数组表示并查集中的父节点，fa数组表示树上的父节点，w数组表示最大载重 
// bool vis[MAXN]; 

// void addedge(int from, int to, int w)
// { //前向星存图 
//     edge2[++cnt].next=head[from];
//     edge2[cnt].to=to;
//     edge2[cnt].w=w;
//     head[from]=cnt;
//     return ;
// }

// bool CMP(Edge1 x, Edge1 y)
// {
//     return x.dis>y.dis; //将边权从大到小排序 
// }

// int find(int x){  //并查集寻找父节点 
//     if(f[x]!=x) f[x]=find(f[x]);
//     return f[x];
// }

// void kruskal()
// {
//     sort(edge1+1, edge1+m+1, CMP); 
//     for(int i=1; i<=n; i++)
//         f[i]=i;  //并查集初始化 
//     for(int i=1; i<=m; i++)
//         if(find(edge1[i].x)!=find(edge1[i].y)){
//             f[find(edge1[i].x)]=find(edge1[i].y);
//             addedge(edge1[i].x, edge1[i].y, edge1[i].dis);
//             addedge(edge1[i].y, edge1[i].x, edge1[i].dis);  //无向图，双向加边 
//         }
//     return ;
// }

// void dfs(int node)
// {
//     vis[node]=true;
//     for(int i=head[node]; i; i=edge2[i].next){ //前向星遍历 
//         int to=edge2[i].to;
//         if(vis[to]) continue;
//         deep[to]=deep[node]+1; //计算深度 
//         fa[to][0]=node; //储存父节点 
//         w[to][0]=edge2[i].w; //储存到父节点的权值 
//         dfs(to);
//     }
//     return ;
// }

// int lca(int x, int y)
// {
//     if(find(x)!=find(y)) return -1; //不连通，输出-1 
//     int ans=INF;
//     if(deep[x]>deep[y]) swap(x,y); //保证y节点更深 
//     //将y节点上提到于x节点相同深度 
//     for(int i=20; i>=0; i--)
//         if(deep[fa[y][i]]>=deep[x]){
//             ans=min(ans, w[y][i]);  //更新最大载重（最小边权） 
//             y=fa[y][i]; //修改y位置 
//         }
//     if(x==y) return ans; //如果位置已经相等，直接返回答案 
//     //寻找公共祖先 
//     for(int i=20; i>=0; i--)
//         if(fa[x][i]!=fa[y][i]){
//             ans=min(ans, min(w[x][i], w[y][i])); //更新最大载重（最小边权）
//             x=fa[x][i]; 
//             y=fa[y][i]; //修改x,y位置 
//         }
//     ans=min(ans, min(w[x][0], w[y][0]));
//     //更新此时x,y到公共祖先最大载重，fa[x][0], fa[y][0]即为公共祖先 
//     return ans;
// }

// int main()
// {
//     int x,y,z,q;
//     scanf("%d%d",&n,&m);
//     for(int i=1; i<=m; i++){
//         scanf("%d%d%d",&x,&y,&z);
//         edge1[i].x=x;
//         edge1[i].y=y;
//         edge1[i].dis=z;
//     } //储存题目所给图 
//     kruskal();
//     for(int i=1; i<=n; i++)
//         if(!vis[i]){ //dfs收集信息 
//             deep[i]=1; 
//             dfs(i);
//             fa[i][0]=i;
//             w[i][0]=INF;
//         }
//     //LCA初始化 
//     for(int i=1; i<=20; i++)
//         for(int j=1; j<=n; j++){
//             fa[j][i]=fa[fa[j][i-1]][i-1]; 
//             w[j][i]=min(w[j][i-1], w[fa[j][i-1]][i-1]);
//         }
//     scanf("%d",&q);
//     for(int i=1; i<=q; i++){
//         scanf("%d%d",&x,&y);
//         printf("%d\n",lca(x,y)); //回答询问 
//     }
//     return 0;
// }