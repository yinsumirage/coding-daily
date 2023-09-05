#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 5e6 + 5;
const ll mod=1e9+7;

int inv[N], jc[N], Jc[N];
void init(int n, int p) {  //用逆元来算组合数
	inv[1] = 1, jc[0] = 1, Jc[0] = 1;
	for(int i = 2; i <= n; i++) inv[i] = 1LL * (p - p / i) * inv[p % i] % p; // 线性求逆元
	for(int i = 1; i <= n; i++) jc[i] = 1LL * jc[i - 1] * inv[i] % p, Jc[i] = 1LL * Jc[i - 1] * i % p; // 线性求阶乘逆元
}

ll n,m,t;
ll D[N]; //错位排序
ll ans=1;

inline ll read(){
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
    fastio;
    t=read();
    ll cnt=1;
    D[0]=1;D[1]=0;
    init(N,mod);
    while(t--){
        n=read(),m=read();
        ans=1;
        ans= 1ll * Jc[n] * jc[m] % mod * jc[n - m] % mod;
        if(n-m>cnt){
            for(int i=cnt+1;i<=n-m;i++){
                D[i]=((i-1)*(D[i-1]+D[i-2]))%mod;
            }
            cnt=n-m;
        }
        ans=(ans*D[n-m])%mod;
        printf("%lld\n",ans);
    }
    //system("pause");
}