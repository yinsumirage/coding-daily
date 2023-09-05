#include<bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fu(i,j,k) for(i=j;i<=k;++i)
#define fd(i,j,k) for(i=j;i>=k;--i)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

struct node{
    double x,y;
}p[2],d;

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
    p[0].x=read(),p[0].y=read();
    p[1].x=read(),p[1].y=read();
    double dy=p[1].y-p[0].y;
    double dx=p[1].x-p[0].x;
    int q=read();
    while(q--){
        d.x=read(),d.y=read();
        double co;
        double dx1=d.x-p[0].x;
        double dy1=d.y-p[0].y;
        co=(dx1*dx+dy1*dy);
        double 
    }

    system("pause");
}