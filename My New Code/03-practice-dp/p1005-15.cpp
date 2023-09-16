#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int Mod = 1e4;
const int N = 85; //高精度四位压缩

int n,m;
int a[N];
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
        printf("\n");
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

HP max(const HP &a,const HP &b){
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

signed main() {
    n=read();
    m=read();
    BaseTwo();
    while(n--){
        for(int i=1;i<=m;i++)a[i]=read();
        memset(dp,0,sizeof(dp));
        for(int j=1;j<=m;j++){
            for(int k=m;k>=j;k--){
                dp[j][k]=max(dp[j][k],dp[j-1][k]+base2[m-k+j-1]*a[j-1]);
                dp[j][k]=max(dp[j][k],dp[j][k+1]+base2[m-k+j-1]*a[k+1]);
            }
        }
        HP ANS;
        for(int j=1;j<=m;j++){
            ANS=max(dp[j][j]+base2[m]*a[j],ANS);
        }
        ans=ans+ANS;
    }
    ans.print();
    system("pause");
}