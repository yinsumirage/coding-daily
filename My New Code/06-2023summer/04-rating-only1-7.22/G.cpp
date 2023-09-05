#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

int n;
int ans=0x3f3f3f3f;

int a[N];
int q[N];

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
    ll sum=1;
    for(int i=1;i<=n;i++)a[i]=read();
    int hh=1,tt=1;
    q[1]=1;
    sum=1;
    printf("%lld\n",sum);
    for(int i=2;i<=n;i++){
        while(hh<=tt&&a[q[tt]]<=a[i]){
            sum^=q[tt]; 
            tt--;
        }
        q[++tt]=i;
        sum^=i;
        printf("%lld\n",sum);
    }
    system("pause");
}