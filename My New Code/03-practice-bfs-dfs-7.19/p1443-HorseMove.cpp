#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

int pan[402][402],tim[402][402];
int n,m,x,y,tal,head;
int moving[8][2]={{-2,-1},{-2,1},{2,-1},{2,1},{-1,-2},{-1,2},{1,-2},{1,2}};
int que[1000005][2];

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

signed main() {
    fastio;
    n=read();
    m=read();
    x=read();
    y=read();
    tal=1,head=0;
    que[1][0]=x;
    que[1][1]=y;
    pan[x][y]=1;
    while(head<tal){
        head++;
        for(int i=0;i<8;i++){
            int x1=que[head][0]+moving[i][0];
            int y1=que[head][1]+moving[i][1];
            if(x1>=1&&x1<=n&&y1>=1&&y1<=m&&pan[x1][y1]==0){
                tal++;
                que[tal][0]=x1;
                que[tal][1]=y1;
                tim[x1][y1]=tim[que[head][0]][que[head][1]]+1;
                pan[x1][y1]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(pan[i][j]==0)printf("-1 ");
            else printf("%d ",tim[i][j]);
        }
        printf("\n");
    }
    //system("pause");
}

