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

int n;
ll a[N];
ll l[N],r[N];
ll ans=0;

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
    for(int i=1;i<=n;i++)a[i]=read();
    l[1]=a[1];r[n]=a[n];
    for(int i=2;i<=n;i++)l[i]=max(a[i],l[i-1]+a[i]);
    for(int i=2;i<=n;i++)l[i]=max(l[i-1],l[i]);
    for(int i=n-1;i>=1;i--)r[i]=max(r[i+1]+a[i],a[i]);
    for(int i=n-1;i>=1;i--)r[i]=max(r[i+1],r[i]);
    ans=l[1]+r[3];
    for(int i=3;i<n;i++)ans=max(ans,l[i-1]+r[i+1]);
    printf("%lld\n",ans);
    system("pause");
}