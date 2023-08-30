#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int maxm = 40005;
const int maxn = 205;
const int INF = 0x3f3f3f3f;

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
struct Edge
{
    int u,v,w,next;
}e[maxm];
int head[maxn],cnt,n,m,s,f[maxn][maxn],t[maxn];
int que,x,y,tim,now;

inline void update(int k){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(f[i][j]>f[i][k]+f[k][j])
            f[i][j]=f[j][i]=f[i][k]+f[k][j];
        }
    }
    return;
}


signed main() {
    fastio;
    n=read();m=read();
    for(int i=0;i<n;i++)t[i]=read();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)f[i][j]=0;
            else f[i][j]=INF;
        }
    }
    for(int i=1,u,v,w;i<=m;i++){
        u=read();v=read();w=read();
        f[u][v]=w;f[v][u]=w;
    }
    que=read();
    now=0;
    while(que--){
        x=read(),y=read(),tim=read();
        while(t[now]<=tim&&now<n){
            update(now);
            now++;
        }
        if(t[x]>tim||t[y]>tim)printf("-1\n");
        else {
            if(f[x][y]==INF)printf("-1\n");
            else printf("%d\n",f[x][y]);
        }
    }
    //system("pause");
}