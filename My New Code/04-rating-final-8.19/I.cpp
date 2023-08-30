#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e3 + 5;

int n,k;
int ans=0x3f3f3f3f;

int vis[N],pri[N],cnt;
int a[N];

void init(int n) {
  for (int i = 2; i <= n; ++i) {
    if (!vis[i]) {
      pri[++cnt] = i;
    }
    for (int j = 1; j <= cnt; ++j) {
      if (1ll * i * pri[j] > n) break;
      vis[i * pri[j]] = 1; //对每个pri前缀标记
      if (i % pri[j] == 0) {
        break;
      }
    }
  }
}

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
    //fastio;
    n=read();
    k=read();
    for(int i=1;i<=n;i++)a[i]=i;
    int sum=n-1;
    init(n);
    if(sum-cnt>k){
        printf("-1");
        return 0;
    }
    pri[0]=1;
    int z=0;
    while(sum-k>=0){
        swap(a[pri[z]],a[pri[z+1]]);
        z++;
        k++;
    }
    for(int i=1;i<=n;i++)printf("%d ",a[i]);
    system("pause");
}