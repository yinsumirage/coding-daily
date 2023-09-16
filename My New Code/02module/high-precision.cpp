#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
const int Mod = 1e4;


int m;

struct HP{
    int p[505],len;
    HP(){
        memset(p,0,sizeof p);
        len=0;
    }
    void print(){
        printf("%d",p[len]);
        for(int i=len-1;i>0;i--){
            if(p[i]==0){
                printf("0000");
                continue;
            }
            for(int k=10;k*p[i]<Mod;k*=10)printf("0");
            printf("%d",p[i]);
        }
    }
}dp[N][N],base2[N],ans;

HP operator + (const HP &a,const HP &b){
    HP c;
    c.len=max(a.len,b.len);
    int x=0;
    for(int i=1;i<=c.len;i++){
        c.p[i]=a.p[i]+b.p[i]+x;
        x=c.p[i]/Mod;
        c.p[i]%=Mod;
    }
    if(x>0)c.p[++c.len]=x;
    return c;
}

HP operator *(const HP &a,const int &b){
    HP c;
    c.len=a.len;int x=0;
    for(int i=1;i<=c.len;i++){
        c.p[i]=a.p[i]*b+x;
        x=c.p[i]/Mod;
        c.p[i]%=Mod;
    }
    while(x>0){
        c.p[++c.len]=x%Mod;
        x/=Mod;
    }
    return c;
}

HP Max(const HP &a,const HP &b){
    if(a.len>b.len)return a;
    else if(a.len<b.len)return b;
    for(int i=a.len;i>0;i--){
        if(a.p[i]>b.p[i])return a;
        else if(a.p[i]<b.p[i])return b;
    }
    return a;
}

void BaseTwo(){
    base2[0].p[1]=1,base2[0].len=1;
    for(int i=1;i<=m+2;i++){
        base2[i]=base2[i-1]*2;
    }
}