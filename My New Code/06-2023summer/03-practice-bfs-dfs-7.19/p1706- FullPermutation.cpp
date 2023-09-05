#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

int n,usd[100],judge[100];


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

void dfs(int x){
    if(x>n){
        for(int i=1;i<=n;i++)printf("%5d",usd[i]);
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++){
        if(!judge[i]){
            judge[i]=1;
            usd[x]=i;
            dfs(x+1);
            judge[i]=0;
        }
    }
}

signed main() {
    fastio;
    n=read();
    dfs(1);
    //system("pause");
    return 0;
}