#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;
int a[1002][1002];
int vis[1002][1002];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

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

int main(){
    n=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%1d",&a[i][j]);
        }
    }

    int x1=read(),y1=read(),x2=read(),y2=read();
    vis[x1][y1]=1;
    q.push(node{x1,y1});
    while(!q.empty()){
        node u=q.front();q.pop();
        for(int i=0;i<4;i++){
            int xx=u.x+dx[i],yy=u.y+dy[i];
            if(a[xx][yy])continue;
            if(xx<1||xx>n||yy<1||yy>n||vis[xx][yy])continue;
            vis[xx][yy]=vis[u.x][u.y]+1;
            if(xx==x2&&yy==y2){
                printf("%d\n",vis[xx][yy]-1);
                return 0;
            }
            q.push(node{xx,yy});
        }
    }
    printf("-1\n");
    system("pause");
}