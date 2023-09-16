#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=0x3f3f3f3f;
const int N = 1e6 + 5;

int n,ans=-1000000;
int b[N];

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

// 超级神奇的一题
// dp?

signed main() {
    n=read();
    int t;
    b[1]=read();
    ans=max(ans,b[1]);
    for(int i=2;i<=n;i++){
        t=read();
        b[i]=max(t+b[i-1],t);
        ans=max(ans,b[i]);
    }
    printf("%d\n",ans);
    system("pause");
}