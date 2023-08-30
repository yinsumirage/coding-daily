#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e4 + 5, M = 2e5 + 5;
int n, m, s, t, tot = 1, lnk[N], ter[M], nxt[M], dep[N], cur[N];
int r[N],c[N];
ll val[N];
ll ans;

void add(int u, int v, ll w) {
  ter[++tot] = v, nxt[tot] = lnk[u], lnk[u] = tot, val[tot] = w;
}

void addedge(int u, int v, ll w) { 
    add(u, v, w), add(v, u, 0); 
}

int bfs(int s, int t) {
  memset(dep, 0, sizeof(dep));
  memcpy(cur, lnk, sizeof(lnk));
  std::queue<int> q;
  q.push(s), dep[s] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = lnk[u]; i; i = nxt[i]) {
      int v = ter[i];
      if (val[i] && !dep[v]) q.push(v), dep[v] = dep[u] + 1;
    }
  }
  return dep[t];
}

ll dfs(int u, int t, ll flow) {
  if (u == t) return flow;
  ll ans = 0,k;
  for (int &i = cur[u]; i && ans < flow; i = nxt[i]) {
    cur[u]=i;
    int v = ter[i];
    if (val[i] && dep[v] == dep[u] + 1) {
      int x = dfs(v, t, min(val[i], flow - ans));
      if (x) val[i] -= x, val[i ^ 1] += x, ans += x;
    }
  }
  if (ans < flow) dep[u] = -1;
  return ans;
}

ll dinic(int s, int t) {
  ll ans = 0;
  while (bfs(s, t)) {
    int x;
    while ((x = dfs(s, t, 1 << 30))) ans += x;
  }
  return ans;
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
    m=read();
    n=read();
    s=0;t=-1;
    for(int i=1;i<=m;i++){
        r[i]=read();
        addedge(s,i,r[i]);
        addedge(i,i+m,1);
    }
    for(int i=1;i<=n;i++){
        c[i]=read();
        addedge(i+m,t,c[i]);
    }
    ans=dinic(s,t);
    if(!ans){
        printf("0\n");return 0;
    }
    printf("1\n");
    for(int i=1;i<=n;i++){
        for(int j=lnk[i];j;j=nxt[j]){
            int v=ter[j];
            if(v!=s&&val[j]){
                printf("%d ",v-m);
            }
        }
        printf("\n");
    }
    printf("%lld\n",ans);
    system("pause");
}