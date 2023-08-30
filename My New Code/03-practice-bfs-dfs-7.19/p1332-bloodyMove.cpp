#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

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


int k[1001][1001],h[1001]={0},ans[1001][1001]={0};
int n,m,a,b;
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int que[10000001][3],tim[1001][1001];//队列与到达时间
bool g[1001][1001]; //是否到达
int king[1000001][2]; //元帅位置

void bfs(int num){
    int tail=num,head=0;
    while(head<tail){
        head++;
        for(int i=0;i<4;i++){
            int x=dx[i]+que[head][0];
            int y=dy[i]+que[head][1];
            if(x>=1&&x<=n&&y>=1&&y<=m&&!g[x][y]){
                tail++;
                que[tail][0]=x;
                que[tail][1]=y;
                que[tail][2]=que[head][2]+1;
                tim[x][y]=que[tail][2];
                g[x][y]=true;
            }
        }
    }
}

signed main() {
    fastio;
    n=read();
    m=read();
    a=read();
    b=read();
    for(int i=1;i<=a;i++){ 
        que[i][0]=read();
        que[i][1]=read();
        g[que[i][0]][que[i][1]]=true;
    }
    for(int i=1;i<=b;i++){
        king[i][0]=read();
        king[i][1]=read();
    }
    bfs(a);
    for(int i=1;i<=b;i++){
        printf("%d\n",tim[king[i][0]][king[i][1]]);
    }
    //system("pause");
}