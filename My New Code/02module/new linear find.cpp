#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 +5 ;

ll phi[N];
int pri[N],cnt,mu[N];
int sum[N];
bool isnp[N];


void inith(int n){
    phi[1]=1;
    for(int i=2;i<=n;i++){
        if(!isnp[i])phi[i]=i-1,pri[++cnt]=i;
        for(int j=1;j<=cnt&&i*pri[j]<=n;j++){
            isnp[i*pri[j]]=1;
            if(i%pri[j]==0){
                phi[i*pri[j]]=phi[i]*pri[j];
                break;
            }
            phi[i*pri[j]]=phi[i]*phi[pri[j]];
        }
    }
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+phi[i];
}

ll calc(int a,int b,int k){
    static int max_rep;
    static long long ans;
    max_rep=min(a,b);ans=0;
    for(int l=1,r;l<=max_rep;l=r+1){
        r=min(a/(a/l),b/(b/l));
        ans+=(1ll*a/(1ll*l*k))*(1ll*b/(1ll*l*k))*(sum[r]-sum[l-1]);
    }
    return ans;
}

void initm(int n){
    mu[1]=1;
    for(int i=2;i<=n;i++){
        if(!isnp[i])mu[i]=-1,pri[++cnt]=i;
        for(int j=1;j<=cnt&&i*pri[j]<=n;j++){
            isnp[i*pri[j]]=1;
            if(i%pri[j]==0)break;
            else mu[i*pri[j]]=-mu[i];
        }
    }
    //for(int i=1;i<=n;i++)sum[i]=sum[i-1]+mu[i];
}