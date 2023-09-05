#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int maxm = 5005;

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

ll n,m,k;
ll ans=0,mod=998244353; 
ll head[maxm],cnt=0,f[maxm][maxm],to[maxm],nxt[maxm];
// fij 到i点走了j步的方法数

inline void add(int u,int v)
{
    to[++cnt]=v;
    nxt[cnt]=head[u];
    head[u]=cnt;
}

signed main() {
    fastio;
    n=read();m=read();k=read();
    for(int i=1,x,y;i<=m;i++){
        x=read();y=read();
        add(x,y);add(y,x);
    }
    f[1][0]=1;
    for(int j=1;j<=k;j++){ //步数层的转移
        int pre=0;
        for(int u=1;u<=n;u++)pre=(pre+f[u][j-1])%mod;//遍历了城市，每次都要实时更新
        for(int u=1;u<=n;u++){
            f[u][j]=pre; //这就是假设所有城市下一步都能到他，再枚举不能到的
            for(int i=head[u];i;i=nxt[i]){// 转移的时候，取出掉那些经过m边的
                f[u][j]=(f[u][j]-f[to[i]][j-1]+mod)%mod; //枚举有边的
            }
            f[u][j]=(f[u][j]-f[u][j-1]+mod)%mod;//减去重复的 即j-1就在u的
        }
    }
    printf("%lld",f[1][k]); //到1点走了k步的总方法数
    //system("pause");
}