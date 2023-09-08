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
const int mod = 2147483647;

int n;
int head[N];
ll dp[N][N]; //一维为底部位置，一维为箭头编号
ll ans=0;

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
    //fastio;
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    n=read();
    for(int i=0;i<=n;i++)head[i]=read();
    dp[head[0]][1]=1;
    for(int i=2;i<=n;i++){ // 遍历后面的块
        for(int j=0;j<=i;j++){
            int tmp=head[j];
            if(tmp<min(head[i],head[i-1])||tmp>max(head[i],head[i-1]))dp[tmp][i]=dp[tmp][i-1]; 
            // 在整个东西的外面，只能和下面的一样
            else if(tmp==head[i-1]){
                if(tmp>=head[i])for(int z=1;z<=tmp-1;z++)dp[tmp][i]=(dp[z][i-1]+dp[tmp][i])%mod;
                else for(int z=tmp+1;z<=n+1;z++)dp[tmp][i]=(dp[z][i-1]+dp[tmp][i])%mod;
            }
            else dp[tmp][i]=0;
        }
    }
    for(int i=1;i<=n+1;i++){
        ans=(dp[i][n]+ans)%mod;
    }
    printf("%lld\n",ans);
    system("pause");
}