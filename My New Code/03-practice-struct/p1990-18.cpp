#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e6 + 5;
const int mod = 1e4;

int n,m;
int dp[N][2];

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
    dp[1][0]=1;
    dp[2][1]=2;
    dp[2][0]=2;
    for(int i=3;i<=n;i++){
        dp[i][0]=dp[i-1][0]+dp[i-2][0]+dp[i-1][1];
        dp[i][0]%=mod;
        dp[i][1]=dp[i-2][0]*2+dp[i-1][1];
        dp[i][1]%=mod;
    }
    printf("%d\n",dp[n][0]);
    system("pause");
}