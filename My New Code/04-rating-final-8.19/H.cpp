#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6;

int prime[N],cnt;
int vis[N],mu[N];

//线性筛
void pre(ll n){
  for(ll i=1;i<=n;i++){
    prime[i]=0;
  }
  mu[1] = 1;
  for (ll i = 2; i <= 1e7; ++i) {
    if (!vis[i]) mu[i] = -1, prime[++cnt] = i;
    for (ll j = 1; j <= cnt && i <= 1e7 / prime[j]; ++j) {
      vis[i * prime[j]] = 1;
      if (i % prime[j] == 0) {
        mu[i * prime[j]] = 0;
        break;
      } else {
        mu[i * prime[j]] = -mu[i];
      }
    }
  }
}

ll count(ll n){
  ll ans=0;
  for(ll i=1;i*i<=n;i++){
    ans+=mu[i]*(n/(i*i));
  }
  return ans;
}


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

int main(){
  pre(1e5+1);;
  ll k=read();
  ll l=k,r=2*k,p=r;
  while(l<=r){
    ll mid=(l+r)/2;
    if(count(mid)>=k)p=mid,r=mid-1;
    else l=mid+1;
  }
  printf("%lld\n",p);
  system("pause");
  return 0;
}