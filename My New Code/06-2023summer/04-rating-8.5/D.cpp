#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

int i,j,l,r;
ll n,m;
ll ans=0x3f3f3f3f;

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
signed main() {
    fastio;
    n=read();
    m=read();
    if(sqrt(m)>n){
        printf("-1\n");
        return 0;
    }
    if(n>=m){
        printf("%lld\n",m);
        return 0;
    }
    int min=1e9;
    for(int i=1;i*i<m;i++){
      if(min>abs(m/i-i))min=i;
    }
    if(min<=n)printf("%lld",m);
    else{
      printf("%lld",m+1);
    }
    system("pause");
}
