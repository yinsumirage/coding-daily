#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=0x3f3f3f3f;
const int N = 2e5 + 5;

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

ll mod;
int m,cnt=0,t=0;
char c;
int x;
ll Max[N][21];

void change(int x){
    Max[x][0]=t;
    for(int i=1;x-(1<<i)>=0;i++)Max[x][i]=max(Max[x][i-1],Max[x-(1<<(i-1))][i-1]);
}

ll query(int l,int r){
    int len=log2(r-l+1);
    return max(Max[r][len],Max[x+(1<<len)-1][len]);//这个不一样
}

signed main() {
    m=read();mod=read();
    for(int i=1;i<=m;i++){
        cin>>c;x=read();
        if(c=='A'){
            cnt++;
            t=(x+t)%mod;
            change(cnt);
        }
        else {
            t=query(cnt-x+1,cnt);
            printf("%lld\n",t);
        }
    }
    system("pause");
}