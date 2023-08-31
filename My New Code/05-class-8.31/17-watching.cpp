#include<iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 5;

int n,t,l;
int cl[N],he[N],clba[N],sk[N];
int clnum,top;

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
        clnum=1,top=1;
        for(int i=1;i<=n;i++)cl[i]=read(),clba[i]=0;
        he[1]=read();
        sk[top]=1;
        clba[cl[1]]++;
        printf("1 ");
        for(int i=2;i<n;i++){
            he[i]=l=read();
            while(top!=0&&he[sk[top]]<=l){
                clba[cl[sk[top]]]--;
                if(clba[cl[sk[top]]]==0)clnum--;
                top--;
            }
            sk[++top]=i;
            clba[cl[sk[top]]]++;
            if(clba[cl[sk[top]]]==1)clnum++;
            printf("%d ",clnum);
        }
        he[n]=l=read();
        while(top!=0&&he[sk[top]]<=l){
            clba[cl[sk[top]]]--;
            if(clba[cl[sk[top]]]==0)clnum--;
            top--;
        }
        sk[++top]=n;
        clba[cl[sk[top]]]++;
        if(clba[cl[sk[top]]]==1)clnum++;
        printf("%d",clnum);
        printf("\n");
    }
    system("pause");
}