#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=0x3f3f3f3f;
const int N = 30;

int n,m;

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

ll t[N],w[N];
ll dp[30005][N];

signed main() {
    //fastio;
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=m;i++){
        t[i]=read(),w[i]=read();
    }
    for(int i=1;i<=m;i++){ //遍历题目数
        for(int j=n;j>=0;j--){ //遍历时间足够的dp
            if(j<=n-t[i])dp[j][i]=max(dp[j][i-1],dp[j+t[i]][i-1]+t[i]*w[i]);
            else dp[j][i]=dp[j][i-1];
        }
    }
    printf("%lld\n",dp[0][m]);
    system("pause");
}