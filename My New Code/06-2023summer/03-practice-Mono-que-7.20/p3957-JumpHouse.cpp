#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 5e5 + 5;

ll n,d,k,ans=0,g,sum=0;
ll x[N],s[N],f[N],q[N];

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

bool check(ll g){
    ll lpo=max((ll)1,d-g);
    ll rpo=d+g;
    if(rpo<x[1])return false;
    memset(f,-1e6,sizeof(f));
    memset(q,0,sizeof(q));
    ll hh=1,tt=0,p=0; //还是要让hh>tt，这样说明里面没有元素
    f[0]=0;            //不然无法判断是否能到第一个点
    for(ll i=1;i<=n;i++){
        if(x[i]>rpo)break;
        if(x[i]<lpo)continue;
        f[i]=s[i];
    }
    for(ll i=1;i<=n;i++){
        while(x[q[hh]]+rpo<x[i]&&hh<=tt)hh++;
        while(x[i]-x[p]>=lpo){
            p++;
            if(x[i]-x[p-1]>rpo)continue;
            while(hh<=tt&&f[q[tt]]<=f[p-1])tt--;
            q[++tt]=p-1;
        }
        if(hh<=tt)f[i]=f[q[hh]]+s[i];
        if(f[i]>=k)return true;
    }
    return false;
}

signed main() {
    fastio;
    n=read();
    d=read();
    k=read();
    for(ll i=1;i<=n;i++){
        x[i]=read();
        s[i]=read();
        if(s[i]>0)sum+=s[i];
    }
    if(sum<k){
        printf("-1\n");
        return 0;
    }
    ll l,r,m; //二分求平均值+判断
    l=0;r=2*x[n];
    m=(l+r)/2;
    while(l<=r){
        if(check(m)){
            ans=m;
            r=m-1;
        }
        else{
            l=m+1;
        }
        m=(l+r)/2;
    }
    printf("%lld\n",ans);
    //system("pause");
    return 0;
}