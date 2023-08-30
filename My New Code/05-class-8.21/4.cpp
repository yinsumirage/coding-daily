#include<iostream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

ll n,h,now,sum,d[N];

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
    n=read();h=read();
    for(int i=1;i<=n;i++){
        now=read();
        d[i]=h-now;
    }
    for(ll i=1;i<=n;i++){
        if(d[i]>d[i-1])sum+=d[i]-d[i-1];
    }
    printf("%lld\n",sum);
    system("pause");
}