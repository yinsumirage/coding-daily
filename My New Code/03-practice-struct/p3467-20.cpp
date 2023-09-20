#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=0x3f3f3f3f;
const int N = 3e5 + 5;

int n;
int x,w[N],sk[N],top,ans;

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

signed main() {
    n=read();
    for(int i=1;i<=n;i++){
        x=read();
        w[i]=read();
    }
    for(int i=1;i<=n;i++){
        while(top>0&&w[sk[top]]>w[i])top--;
        if(w[sk[top]]!=w[i])ans++;
        sk[++top]=i;
    }
    printf("%d",ans);
    system("pause");
}