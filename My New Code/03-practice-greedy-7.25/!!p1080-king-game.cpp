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

int i,j;
ll n,aa,bb;
ll ans=0x3f3f3f3f;

struct prime{
    int l,r;
}a[10000];

bool cmp(prime a,prime b){
    return a.l*a.r<b.l*b.r;
}

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
    aa=read();
    bb=read();
    fup(i,1,n){
        a[i].l=read();
        a[i].r=read();
    }
    sort(a+1,a+n+1);
    pro[0]=1;
    system("pause");
}