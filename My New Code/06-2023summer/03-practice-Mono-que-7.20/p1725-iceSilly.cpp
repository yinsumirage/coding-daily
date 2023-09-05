#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 3e5 + 5;

ll n,l,r,hh,tt,p=0;
int ice[N],q[N];
ll ans=0,f[N];
//p记录最远能到的

ll read(){
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
    n=read();
    l=read();
    r=read();
    for(ll i=0;i<=n;i++){
        ice[i]=read();
    }
    hh=tt=1;
    memset(f,0xcf,sizeof(f)); // 这两步很重要
    ans=f[0];                 // 专门设计了数据，比如答案最终小于零的时候就会WA
    f[0]=0;
    for(ll i=l;i<=n;i++){
        while(hh<=tt&&f[q[tt]]<=f[p])tt--;
        q[++tt]=p;
        while(q[hh]+r<i)hh++;
        f[i]=f[q[hh]]+ice[i];
        p++;
    }
    for(int i=n+1-r;i<=n;i++){
        ans=max(ans,f[i]);
    }
    printf("%lld",ans);
    //system("pause");
}