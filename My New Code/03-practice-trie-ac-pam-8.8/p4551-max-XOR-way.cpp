#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

int n;
int ans=0x3f3f3f3f;
int head[N],nxt[N],to[N],we[N],tot=0;
int dis[N];
int trie[N][2],cnt=1;
bool e[N];

void add(int x,int y,int z){
    to[++tot]=y;
    we[tot]=z;
    nxt[tot]=head[x];
    head[x]=tot;
}

void dfs(int x,int fa){
    for(int i=head[x];i;i=nxt[i]){
        int v=to[i],w=we[i];
        if(v==fa)continue; //除了父节点其他都探索
        dis[v]=w^dis[x];
        dfs(v,x);
    }
    return;
}

void insert(int x){
    int p=1;
    for(int i=31;i>=0;i--){
        int num=((x>>i)&1);
        if(!trie[p][num])trie[p][num]=++cnt;
        p=trie[p][num];
    }
    e[p]=1;
}

int find(int num){ //对一个数进行找，遍历每个点的距离
    int p=1;
    int Sum=0;
    for(int i=31;i>=0;i--){
        int x=((num>>i)&1);
        if(trie[p][x^1]){
            Sum+=(1<<i);
            p=trie[p][x^1];
        }
        else p=trie[p][x];
    }
    return Sum;
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
    for(int i=1;i<n;i++){
        int x,y,z;
        x=read();y=read();z=read();
        add(x,y,z);
        add(y,x,z);
    }
    dis[1]=0;
    dfs(1,0);
    for(int i=1;i<=n;i++){
        insert(dis[i]);
    }
    int Sum=0;
    for(int i=1;i<=n;i++){
        Sum=max(Sum,find(dis[i]));
    }
    printf("%d",Sum);
    //system("pause");
}