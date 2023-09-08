#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=0x3f3f3f3f;
const int N = 2e3+5;
const int mod = 1e7;

int n,v;

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

ll w[N];
ll dp[N][N];

signed main() {
    //fastio;
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    n=read();v=read();
    for(int i=1;i<=n;i++)w[i]=read()%v;
    dp[0][0]=1; // 第i物品后，余数为j的背包数
    for(int i=1;i<=n;i++){
        for(int j=0;j<v;j++)dp[i][j]+=dp[i-1][j];
        for(int j=0;j<v;j++)dp[i][(j+w[i])%v]=(dp[i-1][j]+dp[i][(j+w[i])%v])%mod;
    }
    printf("%d\n",(dp[n][0]-1)%mod);
    system("pause");
}