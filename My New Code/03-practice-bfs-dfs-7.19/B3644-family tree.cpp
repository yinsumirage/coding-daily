#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e3 + 5;

ll n,m,cnt=0;
ll ans=0x3f3f3f3f;

ll head[N],dep[N],to[N],nxt[N];

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

void add(int u,int v){
    cnt++;
    to[cnt]=v;
    nxt[cnt]=head[u];
    head[u]=cnt;
    dep[v]++;
}

queue<int> Q;
void toposort(){
    for(int i=1;i<=n;i++){
        if(dep[i]==0){
            printf("%d ",i);
            Q.push(i);
        }
    }
    while(Q.size()){
        int x=Q.front();
        Q.pop();
        for(int i=head[x];i;i=nxt[i]){
            dep[to[i]]--;
            if(dep[to[i]]==0){
                printf("%d ",to[i]);
                Q.push(to[i]);
            }
        }
    }
}

signed main() {
    fastio;
    n=read();
    for(int i=1,v;i<=n;i++){
        while(v=read()){
            add(i,v);
        }
    }
    toposort();
    //system("pause");
}