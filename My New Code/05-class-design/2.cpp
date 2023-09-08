#include<iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e5 + 5;

int n,v,sum=0;
int a[N],b[N],d[N];

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
    v=read();
    int daym=0,res=0;
    for(int i=1;i<=n;i++){
        a[i]=read(),b[i]=read();
        d[a[i]]+=b[i];
        daym=max(daym,a[i]+1);
    }
    if(d[1]>v){
        sum+=v;
        res=d[1]-v;
    }
    else {
        sum+=d[1];
    }
    for(int i=2;i<=daym;i++){
        if(d[i]+res<=v){
            sum+=d[i]+res;
            res=0;
        }
        else if(res>=v){
            res=d[i];
            sum+=v;
        }
        else {
            res=d[i]+res-v;
            sum+=v;
        }
    }
    printf("%d\n",sum);
    //system("pause");
}