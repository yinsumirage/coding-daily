#include<iostream>
#include<queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e3 + 5;

int n,m,k,ans=-1;
char a[N][N];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

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

struct dian{
    int x,y,stp;
    dian(int xx,int yy,int zz){
        x=xx,y=yy,stp=zz;
    }
};

bool vis[N][N];
queue<dian>q;

int main(){
    n=read(),m=read(),k=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i][j]=getchar();
        }
        getchar();
    }
    int x1=read(),y1=read(),x2=read(),y2=read();
    if(x1==x2&&y1==y2){
        printf("0\n");
        return 0;
    }
    vis[x1][y1]=1;
    q.push(dian(x1,y1,0));
    while(!q.empty()){
        dian u=q.front();q.pop();
        int xx,yy,step;
        for(int i=0;i<4;i++){
            for(int t=1;t<=k;t++){
                xx=u.x+t*dx[i];yy=u.y+t*dy[i];step=u.stp+1;
                if(xx==x2&&yy==y2){
                    ans=step;
                    printf("%d\n",ans);
                    system("pause");
                    return 0;
                }
                if(a[xx][yy]=='#'||xx<1||xx>n||yy<1||yy>m)break;
                if(vis[xx][yy])continue;
                q.push(dian(xx,yy,step));
                vis[xx][yy]=1;
            }
        }
    }
    printf("-1\n");
    system("pause");
}