#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=0x3f3f3f3f;
const int N = 1e3 + 5;

int ans=0;
int n,t;
bool a[N][N];
int le[N][N],ri[N][N],up[N][N];

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
    t=read();
    for(int i=1;i<=t;i++){
        int x=read(),y=read();
        a[x][y]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            le[i][j]=j;
            ri[i][j]=j;
            if(!a[i][j])up[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=2;j<=n;j++){
            if(!a[i][j]&&!a[i][j-1])le[i][j]=le[i][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=n-1;j>=1;j--){
            if(!a[i][j]&&!a[i][j+1])ri[i][j]=ri[i][j+1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i>1&&!a[i][j]&&!a[i-1][j]){
                up[i][j]=up[i-1][j]+1;
                ri[i][j]=min(ri[i][j],ri[i-1][j]);
                le[i][j]=max(le[i][j],le[i-1][j]);
            }
            int aa=ri[i][j]-le[i][j]+1;
            aa=min(aa,up[i][j]);
            ans=max(ans,aa);
        }
    }
    printf("%d\n",ans);
    system("pause");
}