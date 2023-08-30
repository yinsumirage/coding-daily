#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e1 + 5;

ll n,b;
ll sum=0;
ll a[N],c[N];

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
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    b=read();
    int j=2;
    for(int i=1;i<=n-1&&j<=n;i++){
        if(a[i]==a[i-1]){
            c[i]=c[i-1];
            sum+=c[i];
            continue;
        }
        while(a[j]-a[i]<b&&j<=n)j++;
        while(a[j]-a[i]==b&&j<=n){
            c[i]++;
            sum++;
            j++;
        }
    }
    printf("%lld",sum);
    system("pause");
}