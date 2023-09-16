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
int dp[N][N];

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
            if(a[i][j]){dp[i][j]=0;continue;}
            if(i==1||j==1)dp[i][j]=1;
            else {
                int up=dp[i-1][j]+1;
                int le=dp[i][j-1]+1;
                if(up==le){
                    if(a[i-up+1][j-le+1]==0){
                        dp[i][j]=up;
                    }
                    else dp[i][j]=up-1;
                }
                else dp[i][j]=min(up,le);
            }
            ans=max(ans,dp[i][j]);
        }
    }
    printf("%d\n",ans);
    system("pause");
}