#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;

// 二进制枚举了每一种情况
// 在n<20时，2的20次方仍可以在1秒内完成
// 然后对半分别算了两边，重复操作其实加的时间*2

ll n,p,k,a[45],b[45];
ll ans=0,mod=1e9+7;
map<ll,ll>MAP;

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
int main(){
    fastio;
    n=read();
    for(int i=0;i<n;i++)a[i]=read();
    for(int i=0;i<n;i++)b[i]=read();
    k=n/2,p=n-k;
    for(ll s=0;s<(1<<k);s++){
        ll suma=0,sumb=0;
        for(int i=0;i<k;i++){
            if((1<<i)&s){ //判断第i为在s中存不存在
                suma+=a[i];//存在就加上第i位的两个值
                sumb+=b[i];
            }
        }
        MAP[sumb-suma]++; //这个值先加入map中
    }
    for(ll s=0;s<(1<<p);s++){
        ll suma=0,sumb=0;
        for(int i=0;i<p;i++){
            if((1<<i)&s){ 
                suma+=a[k+i];
                sumb+=b[k+i];
            }
        }
        ans=(ans+MAP[suma-sumb])%mod;
    }
    printf("%lld",(ans)%mod);
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// #define PII pair<long,long>
// const int mod=1e9+7;
// int a[45],b[45],n,k,p;
// map<long long,long long> Map;
 
// int main()
// {
//     scanf("%d",&n);
//     for(int i=0;i<n;i++) scanf("%d",&a[i]);
//     for(int i=0;i<n;i++) scanf("%d",&b[i]);
//     k=n/2,p=n-k;
//     long long ans=0;
//     for(int S=0;S<(1<<k);S++){
//         long long suma=0,sumb=0;
//         for(int i=0;i<k;i++)
//             if((1<<i)&S)
//                 suma+=a[i],sumb+=b[i];
//         Map[sumb-suma]++;
//     }
//     for(int S=0;S<(1<<p);S++){
//         long long suma=0,sumb=0;
//         for(int i=0;i<p;i++)
//             if((1<<i)&S)
//                 suma+=a[k+i],sumb+=b[k+i];
//         ans+=Map[suma-sumb];
//     }
//     printf("%lld",(ans)%mod);
// }