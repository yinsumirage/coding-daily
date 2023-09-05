#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

//单调队列分别维护出行和列

int a,b,n;
ll x[1005][1005],qh[1005],ql[1005];
ll hx[1005][1005],hy[1005][1005];
ll lx[1005][1005],ly[1005][1005];
ll ans;


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
    fastio;
    a=read();b=read();n=read();
    for(int i=1;i<=a;i++)
        for(int j=1;j<=b;j++)
            x[i][j]=read();
    int hh,tt,h,t;
    for(int i=1;i<=b;i++){ //每列去看 遍历列数
        hh=1,tt=0;
        h=1,t=0;
        for(int j=1;j<=a;j++){
            while(hh<=tt&&qh[hh]+n<=j)hh++;
            while(h<=t&&ql[h]+n<=j)h++;
            while(hh<=tt&&x[j][i]>x[qh[tt]][i])tt--; //更优直接踢掉尾元素
            while(h<=t&&x[j][i]<x[ql[t]][i])t--;
            qh[++tt]=j;
            ql[++t]=j;
            if(j>=n){
                hx[j-n+1][i]=x[qh[hh]][i];
                lx[j-n+1][i]=x[ql[h]][i]; 
                //失败的经历刚告诉我，永远不要抄上面的代码写下面，h写成hh，调一下午
            }
        }
    }
    
    for(int i=1;i<=a-n+1;i++){ //每行去看
        hh=1,tt=0;
        h=1,t=0;
        for(int j=1;j<=b;j++){ 
            while(hh<=tt&&qh[hh]+n<=j)hh++;
            while(h<=t&&ql[h]+n<=j)h++;
            while(hh<=tt&&hx[i][j]>hx[i][qh[tt]])tt--;
            while(h<=t&&lx[i][j]<lx[i][ql[t]])t--;
            qh[++tt]=j;
            ql[++t]=j;
            if(j>=n){
                hy[i][j-n+1]=hx[i][qh[hh]];
                ly[i][j-n+1]=lx[i][ql[h]];
            }
        }
    }

    ans=0x3f3f3f3f;
    for(int i=1;i<=a-n+1;i++){
        for(int j=1;j<=b-n+1;j++){
            ans=min(ans,hy[i][j]-ly[i][j]);
        }
    }
    printf("%lld\n",ans);
    //system("pause");
}