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

int vis[100][100];
int dx[13]={-2,-1,1,2,2,2,2,1,-1,-2,2,-2};
int dy[13]={2,2,2,2,1,-1,-2,-2,-2,-2,1,-1};
struct node{
    int x,y;
};
queue<node>q;

void bfs(){
    while(!q.empty()){
        int x=q.front().x,y=q.front().y;q.pop();
        for(int i=0;i<12;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx==1&&ny==1){
                printf("%d\n",vis[x][y]);
                return;
            }
            if(nx<1||nx>100||ny<1||ny>100||vis[nx][ny])continue;
            vis[nx][ny]=vis[x][y]+1;
            q.push(node{nx,ny});
        }
    }
}

signed main() {
    int x1=read(),y1=read(),x2=read(),y2=read();
    q.push(node{x1,y1});
    vis[x1][y1]=1;
    bfs();
    memset(vis,0,sizeof(vis));
    while(!q.empty())q.pop();
    q.push(node{x2,y2});
    vis[x2][y2]=1;
    bfs();
    system("pause");
}