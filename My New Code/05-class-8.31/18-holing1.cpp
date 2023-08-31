#include<iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e5 + 5;

int n,h[N],sk[N],top;

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
    sk[0]=-1;
    while(scanf("%d",&n)!=EOF){
        top=1;
        sk[1]=h[1]=read()%2;
        for(int i=2;i<=n;i++){
            h[i]=read()%2;
            if(h[i]==sk[top]){
                top--;
            }
            else {
                sk[++top]=h[i];
            }
        }
        if(top<=1)printf("YES\n");
        else printf("NO\n");
    }
    system("pause");
}