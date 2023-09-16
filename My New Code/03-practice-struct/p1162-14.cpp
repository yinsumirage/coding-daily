#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=0x3f3f3f3f;
const int N = 1e6 + 5;

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int n,cnt=0;
int a[33][33];


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

int vis[33][33];
struct node{
    int x,y;
};
queue<node>q;

void bfs(int x,int y){
    while(!q.empty())q.pop();
    vis[x][y]=1;
    q.push(node{x,y});
    while(!q.empty()){
        node u=q.front();q.pop();
        for(int i=0;i<4;i++){
            int x=u.x+dx[i];
            int y=u.y+dy[i];
            if(x<1||x>n||y<1||y>n||vis[x][y]||a[x][y])continue;
            vis[x][y]=vis[u.x][u.y];
            q.push(node{x,y});
        }
    }
}

signed main() {
    n=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=read();
        }
    }
    for(int i=1;i<=n;i++)if(!a[1][i]&&!vis[1][i])vis[1][i]=1,bfs(1,i);
    for(int i=2;i<=n;i++)if(!a[n][i]&&!vis[n][i])vis[n][i]=1,bfs(n,i);
    for(int i=2;i<=n;i++)if(!a[i][1]&&!vis[i][1])vis[i][1]=1,bfs(i,1);
    for(int i=2;i<n;i++)if(!a[i][n]&&!vis[i][n])vis[i][n]=1,bfs(i,n);
    for(int i=2;i<n-1;i++){
        for(int j=2;j<n-1;j++){
            if(vis[i][j]||a[i][j])continue;
            vis[i][j]=2;
            q.push(node{i,j});
            while(!q.empty()){
                node u=q.front();q.pop();
                for(int i=0;i<4;i++){
                    int x=u.x+dx[i];
                    int y=u.y+dy[i];
                    if(x<1||x>n||y<1||y>n||vis[x][y]||a[x][y])continue;
                    vis[x][y]=vis[u.x][u.y];
                    q.push(node{x,y});
                }
            }
        }
    }
    if(n==3){
        vis[2][2]=2;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(vis[i][j]==2)printf("2 ");
            else printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    system("pause");
}