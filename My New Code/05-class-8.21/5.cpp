#include<iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

int n,t;
ll a[N],lh[N],rh[N];

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
    t=read();
    while(t--){
        ll sum=0;
        n=read();
        for(int i=1;i<=n;i++){
            a[i]=read();
        }
        lh[1]=a[1],rh[n]=a[n];
        for(int i=2;i<n;i++){
            if(a[i]<lh[i-1])lh[i]=lh[i-1];
            else lh[i]=a[i];
        }
        for(int i=n-1;i>1;i--){
            if(a[i]<rh[i+1])rh[i]=rh[i+1];
            else rh[i]=a[i];
        }
        for(int i=2;i<=n-1;i++){
            if(min(rh[i],lh[i])-a[i]>=0)sum+=min(rh[i],lh[i])-a[i];
        }
        printf("%lld\n",sum);
    }
    system("pause");
}