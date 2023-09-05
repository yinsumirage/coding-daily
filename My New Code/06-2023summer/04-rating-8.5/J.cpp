#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

ll n,m,k;
int dian[3];

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
    fastio;
    n=read();
    m=read();
    k=read();
    if(n%m==0){
        printf("000");
        return 0;
    }
    while(n>m){
        n-=m;
    }
    for(int i=1;i<k+3;i++){
        n*=10;
        dian[0]=dian[1];
        dian[1]=dian[2];
        dian[2]=n/m;
        if(n%m==0){
            break;
        }
        n=n%m;
    }
    for(int i=0;i<3;i++){
        printf("%d",dian[i]);
    }
    system("pause");
}