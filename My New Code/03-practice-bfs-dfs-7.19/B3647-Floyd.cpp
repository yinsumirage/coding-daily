#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 105;

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

// struct node{
//     int weight,to,next;
// }way[N];

int n,m,tot=0;
//int head[N];
int dp[N][N];

//建树要好好学习才能掌握好
// void add(int x,int y,int z){
//     way[++tot].weight=z;  //权值
//     way[tot].to=y;   //下个节点
//     way[tot].next=head[x];//作指针
//     head[x]=tot; 
// }

signed main() {
    fastio;
    n=read();m=read();
    memset(dp,0x3f,sizeof(dp));
    for(int i=1,u,v,w;i<=m;i++){
        u=read();
        v=read();
        w=read();
        dp[u][v]=w;
        dp[v][u]=w;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);//dp[i][j]表示从i到j的最短路名字，dp[i][k]表示从i到k的
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)printf("0 ");
            else printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    system("pause");
}