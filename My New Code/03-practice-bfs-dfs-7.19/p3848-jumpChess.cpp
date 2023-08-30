#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

int n,x,y,ans=0;

int a[105][105],f[105][105];
int dx[4]={-1,1,0,0},dy[4]={0,0,1,-1};

ll read(){
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

void dfs(int x,int y,int step){
    ans=max(ans,step);
    for(int i=0;i<4;i++){
        int tx=x,ty=y,s=0;
        while(tx+dx[i]>0&&tx+dx[i]<=n&&ty+dy[i]>0&&ty+dy[i]<=n){
            tx+=dx[i];ty+=dy[i];s++;
            if(a[tx][ty]==0)break;
        }//找到第一个不是边界也不是1的点
        if(tx>0&&tx<=n&&ty>0&&ty<=n&&a[tx][ty]==0&&f[tx][ty]==0&&s!=1){
            f[tx][ty]=1;
            dfs(tx,ty,step+s);
            f[tx][ty]=0;
        }
    }
}

signed main() {
    fastio;
    n=read();x=read();y=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=read();
        }
    }
    f[x][y]=1;
    dfs(x,y,0);
    printf("%d",ans);
    system("pause");
}