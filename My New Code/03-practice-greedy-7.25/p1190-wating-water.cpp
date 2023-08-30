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

ll n,m,i,p,t;
ll w[100000];


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
    m=read();
    fup(i,1,n){
        w[i]=read();
    }
    p=m+1;t=0;
    while(p<=n+1){
        fup(i,1,m){
            w[i]--;
            if(w[i]==0)w[i]=w[p++];
        }
        t++;
    }
    fup(i,2,m){
        if(w[i]>w[1])w[1]=w[i];
    }
    printf("%lld",t+w[1]);
    //system("pause");
}