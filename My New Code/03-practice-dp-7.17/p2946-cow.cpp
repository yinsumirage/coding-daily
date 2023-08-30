#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

int mod=1e8;
int cow[2005];
ll dp[2005][2005]; 
//存前i件东西，余数为j的方案

int main() {
    fastio;
    int n,f;
    cin>>n>>f;

    for(int i=1;i<=n;i++){
        cin>>cow[i];
        cow[i]%=f;
    }
    for(int i=1;i<=n;i++){
        dp[i][cow[i]]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=f-1;j++){
            dp[i][j]=((dp[i][j]+dp[i-1][j])%mod+dp[i-1][(j-cow[i]+f)%f])%mod;
        }
    }
    printf("%d\n",dp[n][0]);
    system("pause");
    return 0;
}

