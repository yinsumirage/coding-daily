#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

char s[1005][1005];
int n,m,now,x,y; //now记录路长
int ans[N][2],f[1005][1005];
bool v[1005][1005];
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};;

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

void dfs(int x,int y){
    now++;
    ans[now][0]=x;ans[now][1]=y; //暂存一下连通块的坐标
    for(int i=0;i<4;i++){
        if(x+dx[i]>0&&x+dx[i]<=n&&y+dy[i]>0&&y+dy[i]<=n&&!v[x+dx[i]][y+dy[i]]&&s[x+dx[i]][y+dy[i]]!=s[x][y]){
            v[x+dx[i]][y+dy[i]]=true;
            dfs(x+dx[i],y+dy[i]);
        }
    }
}

int main() {
    fastio;
    n=read();m=read();
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
        if(!v[i][j]){
            v[i][j]=true;
            now=0;
            dfs(i,j);
            for(int i=1;i<=now;i++)f[ans[i][0]][ans[i][1]]=now;
        }
    }
    while(m--){
        x=read();
        y=read();
        printf("%d\n",f[x][y]);
    }
    //system("pause");
    return 0;
}