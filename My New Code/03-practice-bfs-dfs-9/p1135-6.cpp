#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=0x3f3f3f3f;

int n,a,b,h[205],ans;

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

struct flood{
    int fl,ti;
};
queue<flood>q;

int vis[205];

signed main() {
    //fastio;
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    n=read();a=read();b=read();
    for(int i=1;i<=n;i++)h[i]=read();
    q.push((flood){a,0});
    while(!q.empty()){
        flood u = q.front();q.pop();
        if(b==u.fl){
            printf("%d\n",u.ti);
            system("pause");
            return 0;
        }
        if(u.fl+h[u.fl]<=n&&!vis[u.fl+h[u.fl]]){
            q.push(flood{u.fl+h[u.fl],u.ti+1});
            vis[u.fl+h[u.fl]]=1;
        }
        if(u.fl-h[u.fl]>=1&&!vis[u.fl-h[u.fl]]){
            q.push(flood{u.fl-h[u.fl],u.ti+1});
            vis[u.fl-h[u.fl]]=1;
        }
    }
    printf("-1\n");
    system("pause");
}