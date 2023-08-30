#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

int a,b,x,y,k;

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

void exgcd(int a,int b){
    if(b==0){
        x=1;
        y=0;
        return;
    }
    exgcd(b,a%b);
    k=x;
    x=y;
    y=k-a/b*y;
    return;
}

signed main() {
    a=read();
    b=read();
    exgcd(a,b);
    printf("%d",(x+b)%b);
    //system("pause");
}