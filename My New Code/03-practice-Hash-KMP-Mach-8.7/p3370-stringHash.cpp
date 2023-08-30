#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e5 + 5;

ll n,m,ans=1;
ull base=233;
ull mod1=1e9+7;
ull mod2=1e12+1;
string s;

struct dat{
    ull x,y;
}a[N];

ull hash1(string s){
    ll l=s.size();
    ull ans=0;
    for(int i=0;i<l;i++){
        ans=(ans*base+(ull)s[i])%mod1;
    }
    return ans;
}

ull hash2(string s){
    ll l=s.size();
    ull ans=0;
    for(int i=0;i<l;i++){
        ans=(ans*base+(ull)s[i])%mod2;
    }
    return ans;
}


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

bool cp(dat a,dat b){
    return a.x<b.x;
}
bool cp1(dat a,dat b){
    return a.y<b.y;
}

signed main() {
    n=read();
    for(ll i=1;i<=n;i++){
        cin>>s;
        a[i].x=hash1(s);
        a[i].y=hash2(s);
    }
    sort(a+1,a+n+1,cp);
    sort(a+1,a+n+1,cp1);
    for(ll i=2;i<=n;i++){
        if(a[i].x!=a[i-1].x||a[i].y!=a[i-1].y)ans++;
    }
    printf("%lld\n",ans);
    //system("pause");
}