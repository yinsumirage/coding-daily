#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 100100;

int n,m,u,v,ans=0;
int sum[3];
vector<int> way[10005];
int g[N]; //染颜色和是否染

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

queue<int>q;

bool bfs(int pos){
    g[pos]=1;
    sum[1]=1,sum[2]=0;
    q.push(pos);
    while(!q.empty()){
        int head=q.front();
        q.pop();
        for(int i=0;i<way[head].size();i++){
            int x=way[head][i];
            if(g[x]==g[head])return false; //染不了一点
            if(!g[x]){
                g[x]=g[head]%2+1;
                sum[g[x]]++;
                q.push(x);
            }
        }
    }
    return true; //能染
}

signed main() {
    fastio;
    n=read();
    m=read();
    for(int i=1;i<=m;i++){
        u=read();
        v=read();
        way[u].push_back(v);
        way[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(g[i])continue;
        if(!bfs(i)){
            printf("Impossible");
            return 0;
        }
        else ans+=min(sum[1],sum[2]);
    }
    printf("%d",ans);
    //system("pause");
}
