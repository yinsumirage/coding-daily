#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=0x3f3f3f3f;
const int N = 505;

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

int n,q;
int w[N],v[N],g[N];
int a,b;
int dp[505][505];

signed main() {
    //fastio;
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    n=read();q=read();
    for(int i=1;i<=n;i++)w[i]=read(),v[i]=read(),g[i]=read();
    memset(dp,-5,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=500-w[i];j>=0;j--){
            for(int k=0;k<=500;k++){
                if(dp[j][k]!=-5){ // 记得要从前面有的k更新过来
                    int vv=min(k+v[i],500);
                    dp[j+w[i]][vv]=max(dp[j][k]+g[i],dp[j+w[i]][vv]);
                }
            }
        }
    }
    while(q--){
        a=read(),b=read();
        int ans=-1;
        for(int i=0;i<=a;i++)for(int j=500;j>=b;j--)ans=max(ans,dp[i][j]);
        printf("%d\n",ans);
    }
    system("pause");
}