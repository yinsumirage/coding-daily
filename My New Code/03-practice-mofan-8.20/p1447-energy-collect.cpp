#include<iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 5;

int n,m,sum[N],cnt,phi[N],pri[N];
bool isnp[N];

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

void inith(int n){
    phi[1]=1;
    for(int i=2;i<=n;i++){
        if(!isnp[i])phi[i]=i-1,pri[++cnt]=i;
        for(int j=1;j<=cnt&&i*pri[j]<=n;j++){
            isnp[i*pri[j]]=1;
            phi[i*pri[j]]=phi[i]*phi[pri[j]];
            if(i%pri[j]==0){
                phi[i*pri[j]]=phi[i]*pri[j];
                break;
            }
        }
    }
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+phi[i];
}


ll calc(int a,int b){
    static int max_rep;
    static long long ans;
    max_rep=min(a,b);ans=0;
    for(int l=1,r;l<=max_rep;l=r+1){
        r=min(a/(a/l),b/(b/l));
        ans+=(1ll*a/(1ll*l))*(1ll*b/(1ll*l))*(sum[r]-sum[l-1]);
    }
    return ans;
}

int main(){
    n=read();m=read();
    inith(100000);
    printf("%lld\n",2*calc(n,m)-1ll*n*m);
    system("pause");
}