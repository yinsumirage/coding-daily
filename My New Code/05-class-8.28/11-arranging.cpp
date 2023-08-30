#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define fup(i,n) for(int i=0;i<n;i++)
const int N = 1e5 + 10;

int n;
int x[N],y[N];
ll ya,xa;
ll ans=0;

void arrange(int*x){
    sort(x,x+n);
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
    n=read();
    fup(i,n)x[i]=read(),y[i]=read();
    arrange(x);
    fup(i,n)x[i]-=i;
    arrange(x);arrange(y);
    xa=x[n/2],ya=y[n/2];
    fup(i,n){
        ans+=abs(x[i]-xa);
        ans+=abs(y[i]-ya);
    }
    printf("%lld\n",ans);
    system("pause");
}