#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=0x3f3f3f3f;
const int N = 16385;

int n,m;
int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};
int s[N];
char c;
int sx,sy,ex,ey;

struct node{
    int x,y,tim;
};
queue<node>q;
int see[N];

void bfs(){
    while(!q.empty()){
        node u=q.front();q.pop();
        for(int i=0;i<4;i++){
            int xx=u.x+dx[i];
            int yy=u.y+dy[i];
            if(xx<1||xx>n||yy<1||yy>m)continue;
            if(see[(xx-1)*m+yy]==1||!s[(xx-1)*m+yy])continue;
            if(see[(xx-1)*m+yy]==2){
                printf("%d\n",u.tim+1);
                return;
            }
            see[(xx-1)*m+yy]=1;
            q.push(node{xx,yy,u.tim+1});
        }
    }
    printf("Poor Harry\n");
    return;
}

void init(int n,int m){
    while(!q.empty())q.pop();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            see[(i-1)*m+j]=0;
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
    n=read();
    m=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>c;
            if(c=='O')s[(i-1)*m+j]=1;
        }
    }
    while(1){
        ex=read();ey=read();
        sx=read();sy=read();
        if(sx==0)break;
        if(ex==sx&&ey==sy){
            printf("0\n");
            continue;
        }
        see[(ex-1)*m+ey]=2;
        for(int i=0;i<8;i++){
            int xx=ex,yy=ey;
            while(1){
                xx+=dx[i];
                yy+=dy[i];
                if(xx<1||xx>n||yy<1||yy>m||!s[(xx-1)*m+yy])break;
                see[(xx-1)*m+yy]=2;
            }
        }
        if(see[(sx-1)*m+sy]){
            printf("0\n");
            init(n,m);
            continue;
        }
        q.push(node{sx,sy,0});
        bfs();
        init(n,m);
    }
    system("pause");
}