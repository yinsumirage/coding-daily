#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

ll t;

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
    t=read();
    while(t--){
        ll n=read();
        ll m=n;
        for(ll i=2;i*i<=n;i++){
            while(m%i==0){
                m/=i;
                printf("%lld ",i);
            }
        }
        if(m!=1)printf("%lld",m);
        printf("\n");
    }
    //system("pause");
}