#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

ll n,k,sum=0,num=0;
ll a[25],b[25];

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

bool check(int x){
    if(x==2)return true;
    if(x%2==0)return false;
    for(int i=3;i*i<=x;i++){
        if(x%i==0)return false;
    }
    return true;
}

void dfs(ll p,ll star,ll num){ //p已选择个数 num数字和 star排列不重
    if(p==k){
        if(check(num))sum++;
        return;
    }
    for(ll i=star;i<n;i++){
        dfs(p+1,i+1,num+a[i]);
    }
    return;
}

signed main(){
    fastio;
    n=read();k=read();
    for(int i=0;i<n;i++){
        a[i]=read();
    }
    dfs(0,0,0);
    printf("%lld\n",sum);
    //system("pause");
}