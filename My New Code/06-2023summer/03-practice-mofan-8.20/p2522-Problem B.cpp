#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 60010;

int pri[N],cnt,mu[N],sum[N];
bool isnp[N];
int a,b,c,d,t,k;

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

void init(int n){
    mu[1]=1;
    for(int i=2;i<=n;i++){
        if(!isnp[i])mu[i]=-1,pri[++cnt]=i;
        for(int j=1;j<=cnt&&i*pri[j]<=n;j++){
            isnp[i*pri[j]]=1;
            if(i%pri[j]==0)break;
            else mu[i*pri[j]]=-mu[i];
        }
    }
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+mu[i];
}

ll calc(int a,int b){
    static int max_rep;
    static long long ans;
    max_rep=min(a,b);ans=0;
    for(int l=1,r;l<=max_rep;l=r+1){
        r=min(a/(a/l),b/(b/l));
        ans+=(1ll*a/(1ll*l*k))*(1ll*b/(1ll*l*k))*(sum[r]-sum[l-1]);
    }
    return ans;
}

signed main() {
    //fastio;
    t=read();
    init(60005);
    while(t--){
        a=read(),b=read(),c=read(),d=read();k=read();
        printf("%lld\n",calc(b,d)-calc(b,(c-1))-calc((a-1),d)+calc((a-1),(c-1)));
    }
    system("pause");
}