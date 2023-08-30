#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

int n,m,o,p;
int du[N];
int vis[N];

int head[N],tot;
struct edge{
    int nxt,to,vis=0;
}e[N];

void add(int u,int v){
    e[++tot].to=v;
    e[tot].nxt=head[u];
    head[u]=tot;
}

int insk[N],vis[N],top;

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
        int a=read(),b=read();
        o=read(),p=read();
        if(o^p){
            add(a,b);add(b,a);
            du[a]++;du[b]++;
        }
    }
    for(int i=1;i<=n;i++){
        if(du[i]&1){
            printf("NIE");
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        if(!vis[i])euler(i);
    }
    printf("%d\n",tot);
    for(int i=1;i<=tot;i++){
        printf("%d\n",ans[i].size()-1);
        for(auto x:ans[i])printf("%d ",x);
        printf("\n");
    }

    system("pause");
}