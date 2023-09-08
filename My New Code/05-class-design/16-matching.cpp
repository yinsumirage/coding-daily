#include<iostream>
#include<string.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5 + 5;

int n;
int sk[N],top,kuozuo[N]={0},kuoyou[N]={0},good=0;
int ans=0,ma=0;
char c[N];

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

void insert(char fu){
    if(fu==')'){
        if(sk[top]==-1){
            top--;
        }
        else sk[++top]=1;
    }
    else sk[++top]=-1;
}

int main(){
    n=read();
    for(int i=1;i<=n;i++){
        top=0;
        scanf("%s",c);
        int l=strlen(c);
        for(int j=0;j<l;j++){
            insert(c[j]);
        }
        if(top==0){
            good++;
        }
        if(sk[1]==1&&sk[top]!=-1){
            kuozuo[top]++;
            ma=max(ma,top);
        }
        else if(sk[1]==-1){
            kuoyou[top]++;
            ma=max(ma,top);
        }
    }
    ans+=good/2;
    for(int i=1;i<=ma;i++){
        ans+=min(kuozuo[i],kuoyou[i]);
    }
    printf("%d\n",ans);
    system("pause");
}