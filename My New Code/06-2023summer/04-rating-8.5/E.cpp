#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
#define N 5000050
typedef unsigned long long ull;
const int MAX=5000000;
inline ull read(){
    ull x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
#define ck(x) (x>=mod?x-mod:x)
map<ull,ull> mp;
ull mod,n,Sphi[N],inv6;
int phi[N],primes[N>>2],pn;
bool ntp[N];
ull qpow(ull a,ull b){
	ull ans=1;
	while(b){
		if(b&1)ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
void init(int n){//预处理S(i)
	ntp[1]=true,phi[1]=1;
	for(register int i=2;i<=n;++i){
		if(!ntp[i])primes[++pn]=i,phi[i]=i-1;
		for(int j=1;j<=pn&&primes[j]*i<=n;++j){
			ntp[primes[j]*i]=true;
			if(i%primes[j]==0){
				phi[i*primes[j]]=phi[i]*primes[j];
				break; 
			}
			phi[i*primes[j]]=phi[i]*(primes[j]-1);
		}
	}
	for(register int i=1;i<=n;i++){
		Sphi[i]=Sphi[i-1]+1ull*i*i%mod*phi[i]%mod;
		Sphi[i]=ck(Sphi[i]);
	}
}
inline ull S2(ull n){//平方和
	return n*(n+1)%mod*(2*n+1)%mod*inv6%mod;
}
inline ull S3(ull n){//立方和
	n%=mod;
	return (n*(n+1)/2%mod)*(n*(n+1)/2%mod)%mod;
}
inline ull Get(ull n){//杜教筛求S(n)
	if(n<=MAX)return Sphi[n]%mod;
	if(mp.count(n))return mp[n];
	ull r=0,ans=S3(n);
	for(ull l=2;l<=n;l=r+1){
		r=(n/(n/l));
		ans-=(S2(r)-S2(l-1)+mod)%mod*Get(n/l)%mod;
		ans=ck(ans+mod);
	} 
	return mp[n]=ans;
}
ull Solve(ull n){
	ull r=0,ans=0;
	for(ull l=1;l<=n;l=r+1){//先在外层数论分块一下
		r=(n/(n/l));
		ans+=S3(n/l)*(Get(r)-Get(l-1)+mod)%mod;
		ans=ck(ans);
	}
	return ans;
}
int main(){
	n=read();
	init(MAX),inv6=qpow(6,mod-2);
	printf("%ulld\n",Solve(n));
	system("pause");
}
