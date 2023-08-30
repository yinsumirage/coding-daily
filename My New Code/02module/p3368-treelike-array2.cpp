#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e2 + 5;

ll n,m;
ll ans=0;
ll a[N],c[N];

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


// 区间修改 + 单点查询

ll lowbit(int x){
    return x & -x;
}

void add(int pos,int k){
    for(int i=pos;i<=n;i+=lowbit(i)){
        c[i]+=k;
    }
}

ll ask(int pos){
    int ans=0;
    for(int i=pos;i;i-=lowbit(i))ans+=c[i];
    return ans;
}

signed main() {
    //fastio;
    n=read();
    m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    for(int i=1;i<=n;i++){
        add(i,a[i]-a[i-1]); //差分的第一个是原数
    }
    for(int i=1;i<=m;i++){
        ll op=read(),x=read(),y,k;
        if(op==1){
            y=read();
            k=read();
            add(x,k);
            add(y+1,-k);
        }
        else{
            printf("%lld\n",ask(x));
        }
    }

    system("pause");
}