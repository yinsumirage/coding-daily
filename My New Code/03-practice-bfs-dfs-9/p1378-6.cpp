#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=0x3f3f3f3f;
const int N = 1e6 + 5;

int n;
double xx,yy,xxx,yyy;
double l,r,d,u;
double x[7],y[7],dis[7][7],ans;

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

bool usd[7];
double R[7];

void dfs(int now,double sum){
    if(now==n+1)ans=max(ans,sum);
    for(int i=1;i<=n;i++){
        if(!usd[i]){
            R[i]=min(min(x[i]-l,r-x[i]),min(y[i]-d,u-y[i]));
            for(int j=1;j<=n;j++){
                if(usd[j])R[i]=min(R[i],dis[i][j]-R[j]);
            }
            usd[i]=true;
            if(R[i]<0)R[i]=0;
            dfs(now+1,sum+R[i]*R[i]*3.14159265358979323846);
            usd[i]=false;
        }
    }
}

signed main() {
    //fastio;
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    n=read();
    scanf("%lf%lf",&xx,&yy);
    scanf("%lf%lf",&xxx,&yyy);
    l=min(xx,xxx),r=max(xx,xxx);
    d=min(yy,yyy),u=max(yy,yyy);
    for(int i=1;i<=n;i++){
        x[i]=read();y[i]=read();
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            dis[i][j]=dis[j][i]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
        }
    }
    dfs(1,0.0);
    printf("%d\n",int((u-d)*(r-l)-ans+0.5));
    system("pause");
}