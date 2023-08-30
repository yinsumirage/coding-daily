#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e4 + 1;


bool judge[3005];
int n,x,y,cnt;
int w[3005];

int nt[N],fi[N],to[N],dp[N];
// 链表
// fi用来储存每个节点的链表头指针
//go储存每个节点的所有子节点

void add(int x,int y){
    nt[++cnt]=fi[x];
    fi[x]=cnt;
    to[cnt]=y;
}

void dfs(int x,int fa){
    dp[x]=false;
    for(int i=fi[x];i;i=nt[i]){
        int y=to[i];
        if(y==fa)continue;
        dfs(y,x);
        if(dp[y]==false&&w[x]>w[y])dp[x]=true;
    }
}

int main(){
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++){ 
        cin>>w[i];
    }
    for(int i=1;i<n;i++){
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    for(int i=1;i<=n;i++){
        memset(dp,0,sizeof dp);
        dfs(i,0);
        if(dp[i])printf("%d ",i);
    }

    system("pause");
    return 0;
}