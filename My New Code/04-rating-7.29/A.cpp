#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 5;

// 分块题
// 我不会的

int i,j,l,r,a[N],x;
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
    for(int i=0;i<n;i++){
        a[i]=read();
    }
    while(n--){
        l=read();
        r=read();
        x=read();
        int sum=0;
        for(int i=l;i<=r;i++){
            if(a[i]==x)sum++;
            else a[i]=x;
        }
        printf("%d\n",sum);
    }
    system("pause");
}