#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int N = 1e5 + 5;

int n,b;
int now=0,res=0,ans=0;
int v[22];
int dp[N];

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

signed main() {
    n=read();
    b=read();
    for(int i=1;i<=N;i++){
        dp[i]=INF;
    }
    dp[0]=0;
    for(int i=1;i<=b;i++){
        v[i]=read();
    }
    for(int i=1;i<=b;i++){
        for(int j=v[i];j<=N;j++){
            dp[j]=min(dp[j],dp[j-v[i]]+1);
        }
    } // 确实是完全背包 可以选多次一头牛 有倍数情况
    for(int i=1;i<=n;i++){
        now=read();
        now-=res;res+=now;
        res-=res?1:0;
        if(now<0){
            printf("-1");
            return 0;
        }
        if(dp[now]==INF){
            printf("-1");
            return 0;
        }
        ans+=dp[now];
    }
    printf("%d\n",ans);
    system("pause");
}