#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define fu(i,j,k) for(i=j;i<=k;++i)
#define fd(i,j,k) for(i=j;i>=k;--i)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 5e4 + 5;

set<int> s;
map<int,int> M;
int pre[10000][N],cnt=0;
int n,m;

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
    m=read();
    for(int i=1;i<=n;i++){
        int x=read();
        if(s.find(x)==s.end()){
            s.insert(x);
            cnt++;
            M[x]=cnt;
        }
        for(auto j=s.begin();j!=s.end();j++){
            if(x==*j)pre[M[*j]][i]=pre[M[*j]][i-1]+1;
            else pre[M[*j]][i]=pre[M[*j]][i-1];
        }
    }
    for(int i=1;i<=m;i++){
        int l=read(),r=read(),v=read(),sum,tot=0;
        for(auto j=s.begin();j!=s.end();j++){
            sum=pre[M[*j]][r]-pre[M[*j]][l-1];
            if(sum!=0&&__gcd(sum,v)==1)tot++;
        }
        printf("%d\n",tot);
    }
    //system("pause");
}