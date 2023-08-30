#include<iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 5;

int n;

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
    for(int i=0;i<=n;i++)printf("%d\n",i);
    system("pause");
}