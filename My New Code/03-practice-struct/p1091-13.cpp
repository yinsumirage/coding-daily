#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=0x3f3f3f3f;
const int N = 1e4 + 5;

int n;
int a[N];
int up[N],dow[N];
int ans=0;

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
        a[i]=read();
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[i]>a[j]&&up[i]<=up[j]+1)up[i]=up[j]+1;
        }
    }
    for(int i=n-1;i>=1;i--){
        for(int j=n;j>i;j--){
            if(a[i]>a[j]&&dow[i]<=dow[j]+1)dow[i]=dow[j]+1;
        }
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,up[i]+dow[i]+1);
    }
    printf("%d\n",n-ans);
    system("pause");
}