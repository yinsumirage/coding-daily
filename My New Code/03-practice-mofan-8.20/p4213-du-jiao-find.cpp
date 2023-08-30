#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 6e6 + 5;

int t;
int pri[N],cnt,mu[N];
ll phi[N];
int sum[N];
bool isnp[N];
unordered_map<int,int>ans_mu;
unordered_map<int,ll>ans_phi;

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

ll get_phi(ll x){
    if(x<=N)return phi[x];
    if(ans_phi[x])return ans_phi[x];
    ll ans=((1ll+x)*x)/2ll;
    for(ll l=2,r;l<=x;l=r+1){
        r=x/(x/l);
        ans-=1ll*(r-l+1)*get_phi(x/l);
    }
    return ans_phi[x]=ans;
}

int get_mu(ll x){
    if(x<=N)return mu[x];
    if(ans_mu[x])return ans_mu[x];
    ll ans=1;
    for(ll l=2,r;l<=x;l=r+1){
        r=x/(x/l);
        ans-=(r-l+1)*get_mu(x/l);
    }
    return ans_mu[x]=ans;
}

void initall(int n){
    mu[1]=1;phi[1]=1;
    for(int i=2;i<=n;i++){
        if(!isnp[i])mu[i]=-1,phi[i]=i-1,pri[++cnt]=i;
        for(int j=1;j<=cnt&&i*pri[j]<=n;j++){
            isnp[i*pri[j]]=1;
            if(i%pri[j]==0){
                phi[i*pri[j]]=phi[i]*pri[j];
                break;
            }
            phi[i*pri[j]]=phi[i]*phi[pri[j]];
            mu[i*pri[j]]=-mu[i];
        }
    }
    for(int i=1;i<=n;i++){
        mu[i]+=mu[i-1];phi[i]+=phi[i-1];
    }
}

int main(){
    t=read();
    initall(N);
    while(t--){
        ll x=read();
        printf("%lld %d\n",get_phi(x),get_mu(x));
    }
    //system("pause");
}