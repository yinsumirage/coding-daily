#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;
int n,m,k,s,t,q,x,y;

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

int main(){
    n=read();
    q=read();
    k=read();
    while(q--){
        x=read();y=read();
        int shu=__gcd(x,y);
        if(shu==x||shu==y){
            if(abs(x-y)<=k){
                printf("lai\n");
                continue;
            }
        }
        else {
            int lca=x*y/shu;
            if(lca*2-x-y<=k){
                printf("lai\n");
                continue;
            }
        }
        printf("rulai\n");
    }
    system("pause");
}