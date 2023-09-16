#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=0x3f3f3f3f;
const int N = 1e5 + 5;

int n;
int ji[2*N];
int ans=0,sum1=0,sum0=0;

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
    for(int i=1,t;i<=n;i++){
        t=read();
        if(t)sum1++;
        else sum0++;
        if(sum1==sum0){
            ans=max(ans,i);
        }
        else {
            if(ji[sum1-sum0+N]==0)ji[sum1-sum0+N]=i;
            else ans=max(ans,i-ji[sum1-sum0+N]);
        }
    }
    printf("%d\n",ans);
    system("pause");
}