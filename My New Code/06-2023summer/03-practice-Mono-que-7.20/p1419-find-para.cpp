#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 5;

// 二分答案
// 通过二分平均值的办法
// 从判断价值最大 
// 转化为了判断减去平均值后区间值是否大于零

int ans=0x3f3f3f3f;

int n,s,t;
double a[N],sum[N];
int q[N];


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

bool check(double x){
    int hh=1,tt=0;
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i]-x;
    }
    for(int i=s;i<=n;i++){
        while(hh<=tt&&sum[q[tt]]>sum[i-s])tt--;
        q[++tt]=i-s;
        if(i>q[hh]+t)hh++;
        if(sum[i]-sum[q[hh]]>0)return true;
    }
    return false;
}
//要是存在sum[i]-min(sum[i-t]~sum[i-s])>0说明mid不够大

signed main() {
    fastio;
    n=read();
    s=read();
    t=read();
    for(int i=1;i<=n;i++)a[i]=read();
    double l=-10000,r=10000;
    sum[0]=0;
    while(r-l>1e-8){
        double mid=(l+r)/2;
        if(check(mid))l=mid;
        else r=mid;
    }
    printf("%.3f",l);
    //system("pause");
}