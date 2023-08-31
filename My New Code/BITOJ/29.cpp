#include<iostream>
#include<bitset>
using namespace std;
const int maxn=3e7+5;
bitset<maxn> f;
long long l,r,ans;
int main(){
    long long i,j;
    cin>>l>>r;
    for(i=3;i*i<=r;i+=2){
        if(!f[i]){
            for(j=i*i;j<=r;j+=2*i)f[j]=1;
        }
    }
    for(i=5;i<=r;i+=4){
        if(l<=i&&!f[i])ans++;
    }
    printf("%lld",ans);
}