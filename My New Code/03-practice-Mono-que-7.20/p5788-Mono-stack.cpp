#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

int n,a[N*3],stk[N*3],f[N*3];
// a存原数组 stk模拟栈 存下标的单调栈 f存结果

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
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    int hh=0;
    for(int i=n;i>=1;i--){
        while(hh>0&&a[stk[hh]]<=a[i])hh--; //栈顶元素比入栈元素小 栈不空 把垃圾弹掉
        f[i]=stk[hh];
        stk[++hh]=i;
    }
    for(int i=1;i<=n;i++){
        printf("%d ",f[i]);
    }
    //system("pause");
}