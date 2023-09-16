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

int n,sum=0,ans=-1e6;
int a[N];
int up[N],dow[N];
int mup[N],mdow[N];

// 环状最大两端子段和
// 子段和首先有点像模版了草


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
    for(int i=1;i<=n;i++)a[i]=read(),sum+=a[i];
    up[1]=a[1];dow[n]=a[n];
    mup[1]=-a[1];mdow[n]=-a[n];
    for(int i=2;i<=n;i++)up[i]=max(a[i],a[i]+up[i-1]);
    for(int i=2;i<=n;i++)up[i]=max(up[i],up[i-1]);
    for(int i=n-1;i>0;i--)dow[i]=max(dow[i+1]+a[i],a[i]);
    for(int i=n-1;i>0;i--)dow[i]=max(dow[i+1],dow[i]);
    for(int i=1;i<n;i++)ans=max(ans,up[i]+dow[i+1]);

    for(int i=2;i<=n;i++)mup[i]=max(-a[i],-a[i]+mup[i-1]);
    for(int i=2;i<=n;i++)mup[i]=max(mup[i],mup[i-1]);
    for(int i=n-1;i>0;i--)mdow[i]=max(mdow[i+1]-a[i],-a[i]);
    for(int i=n-1;i>0;i--)mdow[i]=max(mdow[i+1],mdow[i]);
    if(ans>=0)for(int i=1;i<n;i++)ans=max(ans,sum+mup[i]+mdow[i+1]);

    printf("%d\n",ans);
    system("pause");
}