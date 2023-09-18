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
int ex,ey;
char c;
int vis[N][N];
bool s[N][N];
int dr[10]={1,2,4,8,16,32,64,128,256,512};
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int xsum[N][N];
int ysum[N][N];

struct node{
    int x,y;
};
queue<node>q;

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
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            while(c=getchar()){
                if(c=='#'){
                    ex=i;ey=j;
                    s[i][j]=1;
                    xsum[i][j]=xsum[i-1][j];
                    ysum[i][j]=ysum[i][j-1];
                    break;
                }
                if(c=='$'||c=='.'){
                    xsum[i][j]=xsum[i-1][j];
                    ysum[i][j]=ysum[i][j-1];
                    s[i][j]=1;break;
                }
                if(c=='X'){
                    if(i==1&&j==1){  // 什么sb数据？
                        s[i][j]=1;   // 在初始点也变成障碍
                        xsum[i][j]=xsum[i-1][j];
                        ysum[i][j]=ysum[i][j-1];
                        break;
                    }
                    xsum[i][j]=xsum[i-1][j]+1;
                    ysum[i][j]=ysum[i][j-1]+1;
                    break;
                }
            }
        }
    }
    q.push(node{1,1});
    vis[1][1]=1;
    while(!q.empty()){
        node u=q.front();q.pop();
        for(int i=0;i<4;i++){
            for(int j=0;j<=9;j++){
                int xx=u.x+dx[i]*dr[j];
                int yy=u.y+dy[i]*dr[j];
                if(xx<1||xx>n||yy<1||yy>m)break;
                // 判断有无障碍出问题了 要前缀和
                if(i==0||i==1){ //左右
                    if(ysum[xx][yy]-ysum[xx][u.y-1])break;
                }
                else {
                    if(xsum[xx][yy]-xsum[u.x-1][yy])break;
                }
                if(vis[xx][yy])continue;
                vis[xx][yy]=vis[u.x][u.y]+1;
                if(xx==ex&&yy==ey){
                    printf("%d\n",vis[xx][yy]-1);
                    system("pause");
                    return 0;
                }
                q.push(node{xx,yy});
            }
        }
    }
    printf("-1\n");
    system("pause");
}