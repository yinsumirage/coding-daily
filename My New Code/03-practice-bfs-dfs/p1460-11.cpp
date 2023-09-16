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

int v,g;
int mi = INF,ji[30];
int vit[30],sl[20][30],ans[30];

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

bool check(int x){
    for(int i=1;i<=v;i++){
        int sum=0;
        for(int j=1;j<=x;j++){
            sum+=sl[ji[j]][i];
        }
        if(sum<vit[i])return false;
    }
    return true;
}

void dfs(int now,int nub){
    if(now>g){
        if(check(nub)){
            if(nub<mi){
                mi=nub;
                for(int i=1;i<=mi;i++){
                    ans[i]=ji[i];
                }
            }
        }
        return ;
    }
    ji[nub+1]=now;
    dfs(now+1,nub+1);
    ji[nub+1]=0;
    dfs(now+1,nub);
}

signed main() {
    v=read();
    for(int i=1;i<=v;i++)vit[i]=read();
    g=read();
    for(int i=1;i<=g;i++){
        for(int j=1;j<=v;j++){
            sl[i][j]=read();
        }
    }
    dfs(1,0);
    printf("%d ",mi);
    for(int i=1;i<=mi;i++){
        printf("%d ",ans[i]);
    }
    system("pause");
}