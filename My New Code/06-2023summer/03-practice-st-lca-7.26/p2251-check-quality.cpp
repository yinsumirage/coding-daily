#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define fup(i,j,k) for(i=j;i<=k;++i)
#define fdo(i,j,k) for(i=j;i>=k;--i)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

// 不是这什么垃圾题目？这不是纯纯滑动窗口
// 单调队列的码少，还更快

int i,j,l,r;
ll n,m;
int Min[N][21];

inline ll read(){
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

int query(int l,int r){
    int len=log2(r-l+1);
    return min(Min[l][len],Min[r-(1<<len)+1][len]);
}

signed main() {
    fastio;
    n=read();
    m=read();
    fup(i,1,n){
        Min[i][0]=read();
    }
    fup(j,1,21){
        for(i=1;i+(1<<j)-1<=n;i++){
            Min[i][j]=min(Min[i][j-1],Min[i+(1<<(j-1))][j-1]);
        }
    }
    l=m;
    while(l<=n){
        printf("%d\n",query(l-m+1,l));
        l++;
    }
    //system("pause");
}