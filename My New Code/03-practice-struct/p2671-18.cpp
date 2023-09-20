#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=0x3f3f3f3f;
const int N = 1e5 + 5;
const int mod = 10007;

ll n,m,num[N];
ll sum1[3][N],sum2[3][N];
ll cnt[2][N];
ll col,ans=0;

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
    n=read();m=read();
    for(int i=1;i<=n;i++){
        num[i]=read();
    }
    for(int i=1;i<=n;i++){
        col=read();
        if(i%2){
            ans=(ans+sum1[0][col]+i*sum1[1][col]%mod+num[i]*sum1[2][col]%mod+cnt[0][col]*i*num[i]%mod)%mod;
            sum1[0][col]=(sum1[0][col]+num[i]*i)%mod;
            sum1[1][col]=(sum1[1][col]+num[i])%mod;
            sum1[2][col]=(sum1[2][col]+i)%mod;
            cnt[0][col]++;
        }
        else {
            ans=(ans+sum2[0][col]+i*sum2[1][col]%mod+num[i]*sum2[2][col]%mod+cnt[1][col]*i*num[i]%mod)%mod;
            sum2[0][col]=(sum2[0][col]+num[i]*i)%mod;
            sum2[1][col]=(sum2[1][col]+num[i])%mod;
            sum2[2][col]=(sum2[2][col]+i)%mod;
            cnt[1][col]++;
        }
    }
    printf("%lld\n",ans);
    system("pause");
}