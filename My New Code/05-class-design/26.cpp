#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

int a[1001][1001],h[1001]={0},ans[1001][1001]={0};

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
    int x,y,a,b;
    x=read()+2;
    y=read()+2;
    a=read()+2;
    b=read()+2;
    int mx[9]={0,-2,-1,1,2,2,1,-1,-2};
    int my[9]={0,1,2,2,1,-1,-2,-2,-1};
    ll p[30][30]={0};
    ll guo[30][30]={0};
    p[2][1]=1;
    for(int i=0;i<9;i++){
        guo[mx[i]+a][my[i]+b]=1;
    }
    for(int i=2;i<=x;i++){
        for(int j=2;j<=y;j++){
            if(guo[i][j]){continue;}
            p[i][j]=p[i-1][j]+p[i][j-1];
        }
    }
    printf("%lld\n",p[x][y]);
    //system("pause");
}