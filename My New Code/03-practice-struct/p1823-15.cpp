#include <bits/stdc++.h>
using namespace std;
//#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,int> pii;
const int INF=0x3f3f3f3f;
const int N = 5e5 + 5;

int n,m;
ll h,res;
stack<pii>s;

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
    for(int i=1;i<=n;i++){
        h=read();
        pii p=make_pair(h,1);
        for(;!s.empty()&&s.top().first<=h;s.pop()){
            res+=s.top().second;
            if(s.top().first==h)p.second+=s.top().second;
        }
        if(!s.empty())++res;
        s.push(p);
    }
    printf("%lld\n",res);
    //system("pause");
}