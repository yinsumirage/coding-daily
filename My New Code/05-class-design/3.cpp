#include<iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

ll n,t;

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
        n=read();
        if(n==1){
            printf("0\n");
            continue;
        }
        n--;
        int sum=1;
        while(n!=1){
            n/=2;
            sum++;
        }
        printf("%d\n",sum);
    }
    //system("pause");
}