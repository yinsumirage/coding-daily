#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=0x3f3f3f3f;
const int N = 3e6 + 5;

int n,x,y,lim=0;
int ri[N],len[N];
int f[N];


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
    for(int i=1;i<=n;i++){
        x=read();y=read();
        len[x]=y-x+1;
        ri[x]=y; // 这样登记主要是他没有重复的从一个点开始
        lim=max(lim,y); // 不然要vector存多个 读到一个i遍历他所有可通向点
    }
    for(int i=lim;i;i--){ // 反向更新了
        if(len[i])f[i]=max(f[i+1],f[ri[i]+1]+len[i]);
        else f[i]=f[i+1];
    }
    printf("%d\n",f[1]);
    system("pause");
}