#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e7 + 5;

//滑动窗口找两个最大的值，单调队列找不到第二个

ll n,m;
ll ans=0;
ll mod=1e9+7;

ll v[N];
priority_queue< pair<ll,ll> > q;

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
    n=read();m=read();
    v[1]=read();
    for(int i=2;i<=n;i++){
        v[i]=(v[i-1]*v[i-1]%(mod)+114514)%(mod);
    }
    for(int i=1;i<=n;i++){
        q.push(make_pair(v[i],i));
        while(q.top().second+m<i)q.pop();
        if(i>=m){
            int ma=q.top().first;
            int mi=q.top().second;
            q.pop();
            ans=max(ans,ma+q.top().first);
            q.push(make_pair(ma,mi));
        }
    }
    printf("%lld\n",ans);
    system("pause");
}