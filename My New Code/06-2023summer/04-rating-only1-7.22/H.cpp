#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

// 分解因式？分解出来从小到大放到位置上

ll n,ma=10;
ll ans=0x3f3f3f3f;
ll te[N];
ll maxn=pow(9,18);

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

void find(int x){

}

signed main() {
    fastio;
    n=read();
    for(int i=1;i<=9;i++)te[i]=i+1;
    ma=9;
    for(int i=1,k;i<=n;i++){
        k=read();
        if(k>maxn){
            printf("Genshin Start\n");
            continue;
        }
        if(k<ma)find(k);
    }
    system("pause");
}