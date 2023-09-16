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

int n,m;
int a[105][105];

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

int vis[105][105]={0};
int cnt=0;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

void dfs(int x,int y){
    vis[x][y]=1;
    for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(vis[xx][yy]||a[xx][yy]==0)continue;
        dfs(xx,yy);
    }
}

signed main() {
    //fastio;
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%1d",&a[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]!=0&&vis[i][j]==0){
                dfs(i,j);
                cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    system("pause");
}