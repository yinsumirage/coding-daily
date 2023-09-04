#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
int si,sj;
char a[101][101];
bool vis[101][101][50];
char c;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};

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
        x=xx;y=yy;stp=zz;
    }
};

queue<dian>q;

int main(){
    int t=read();
    while(t--){
        int ans=-1;
        n=read();m=read(),k=read();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if((a[i][j]=getchar())=='S')si=i,sj=j;
            }
            getchar();
        }
        memset(vis,0,sizeof(vis));
        while(!q.empty())q.pop();
        q.push(dian(si,sj,0));
        vis[si][sj][0]=1;
        while(!q.empty()){
            dian u=q.front();q.pop();
            if(a[u.x][u.y]=='E'){
                ans=u.stp;break;
            }
            int xx,yy,step;
            for(int i=0;i<4;i++){
                xx=u.x+dx[i],yy=u.y+dy[i],step=u.stp+1;
                if(xx<1||xx>n||yy<1||yy>m||a[xx][yy]=='#'||vis[xx][yy][step%k]||(a[xx][yy]=='*'&&(step%k)))continue;
                q.push(dian(xx,yy,step));
                vis[xx][yy][step%k]=1;
            }
        }
        if(ans==-1)printf("-1\n");
        else printf("%d\n",ans);
    }
    system("pause");
}