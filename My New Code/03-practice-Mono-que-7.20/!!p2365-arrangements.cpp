#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N =  5005;

// 本题涉及了斜率优化 可以放一放在学

int n,s;
int t[N],f[N];
int ans=0x3f3f3f3f;

int a[1001][1001],h[1001]={0},b[1001][1001]={0};

ll read(){
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
    fastio;
    n=read();s=read();
    for(int i=1;i<=n;i++){
        t[i]=read();f[i]=read();
    }
}