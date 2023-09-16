#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=0x3f3f3f3f;
const int N = 2e5 + 5;

int n,m,ans=0,idn;
int pre[N],nxt[N];
bool vis[N];
struct node{
    int id,va;
    bool operator<(const node &x)const{return x.va>va;}
}a[N];
priority_queue<node>q;

void de(int x){
    vis[x]=1;
    nxt[pre[x]]=nxt[x];
    pre[nxt[x]]=pre[x];
}

int getid(){
    while(1){
        node u=q.top();
        q.pop();
        if(!vis[u.id])return u.id;
    }
}

// 退流策略 用优先队列维护一个从大到小的权值
// 选堆顶 ans+=a[i]
// 然后前后趋删掉 加入a[i]=a[prei]+a[nxti]-a[i] 退流
// 如果新的a[i]又选上了 说明prei+nxti更优 再选的时候
// ans+=这个权值自动推掉了[i]

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
    m=read();
    if(2*m>n){
        printf("Error!");
        return 0;
    }
    for(int i=1;i<=n;i++){
        a[i].va=read(),a[i].id=i;
        q.push(node{i,a[i].va});
    }
    for(int i=2;i<=n-1;i++){
        pre[i]=i-1;nxt[i]=i+1;
    }
    pre[1]=n;nxt[1]=2;pre[n]=n-1;nxt[n]=1;
    for(int i=1;i<=m;i++){
        idn=getid();
        ans+=a[idn].va;
        a[idn].va=a[pre[idn]].va+a[nxt[idn]].va-a[idn].va;
        q.push(node{idn,a[idn].va});
        de(pre[idn]);de(nxt[idn]);
    }
    printf("%d\n",ans);
    system("pause");
}