#include<iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e5 + 5;

int n;
int sk[N],top,h[N],ma;

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

//面对无限组的数据
//最好先读完所有数据，在进行判断，不然break一下出去，数据读少了，寄

int main(){
    sk[0]=1e9+1;
    while (scanf("%d",&n)!=EOF){
        ma=0;
        for(int i=1;i<=n;i++)h[i]=read(),ma=max(ma,h[i]);
        top=1;
        sk[1]=h[1];
        for(int i=2;i<=n;i++){
            if(h[i]==sk[top])top--;
            else if(h[i]>sk[top]){top=2;break;}
            else sk[++top]=h[i];
        }
        if(top==0)printf("YES\n");
        else if(top==1&&sk[1]==ma)printf("YES\n");
        else printf("NO\n");
    }
    system("pause");
}