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

int n,m;
ll ans=0;
bool a[N][N];
int le[N][N],ri[N][N],up[N][N];

signed main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;
            cin>>c;
            if(c=='R')a[i][j]=1;
            else {
                le[i][j]=j;
                ri[i][j]=j;
                up[i][j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=2;j<=m;j++){
            if(!a[i][j]&&!a[i][j-1])le[i][j]=le[i][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=m-1;j>=1;j--){
            if(!a[i][j]&&!a[i][j+1])ri[i][j]=ri[i][j+1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i>1&&!a[i][j]&&!a[i-1][j]){
                up[i][j]=up[i-1][j]+1;
                le[i][j]=max(le[i][j],le[i-1][j]);
                ri[i][j]=min(ri[i][j],ri[i-1][j]);
            }
            int aa=ri[i][j]-le[i][j]+1;
            ans=max(ans,1ll*aa*up[i][j]);
        }
    }
    printf("%d\n",ans*3);
    system("pause");
}