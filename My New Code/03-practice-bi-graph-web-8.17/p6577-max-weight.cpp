#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e4 + 5;

int n,m,t,ans=0;
int match[N];
bool a[N][N],vis[N];

bool dfs(int x){
    for(int i=1;i<=m;i++){ //寻找x能去的对边
        if(!vis[i]&&a[x][i]){ 
            vis[i]=1;
            if(!match[i]||dfs(match[i])){//没匹配或者让前面的一个个向前试
                match[i]=x;
                return 1;
            }
        }
    }
    return 0;
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
    m=read();
    for(int i=1;i<=m;i++){
        int u=read(),v=read(),w=read();
        a[u][v]=1;
    }
    for(int i=1;i<=n;i++){
        ans+=dfs(i);
        for(int i=1;i<=m;i++)vis[i]=0;
    }
    printf("%d\n",ans);
    system("pause");
}