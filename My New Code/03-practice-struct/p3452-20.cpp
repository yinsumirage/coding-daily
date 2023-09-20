#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=0x3f3f3f3f;
const int N = 4e6 + 5;

int n,m;
bool vis[N],cov[N];
int kuai[N];
int nx[N],la[N]; //相当于整个链表 但是懒得写链表 硬存了
int ans;
queue<int>q;

int head[N],cnt;

void dele(int x){
    nx[la[x]]=nx[x];
    la[nx[x]]=la[x];
}

struct edge{
    int v,nxt;
}e[N];

void add(int u,int v){
    e[++cnt].nxt=head[u];
    e[cnt].v=v;
    head[u]=cnt;
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
    n=read();
    m=read();
    for(int i=1;i<=m;i++){
        int a=read(),b=read();
        add(a,b);add(b,a);
    }
    nx[0]=1;
    for(int i=1;i<n;i++){
        la[i+1]=i;
        nx[i]=i+1;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            // 没被访问过 就开个新块装下去 入队删掉
            kuai[++ans]=1;
            vis[i]=1;
            q.push(i);
            dele(i);
            while(!q.empty()){
                int x=q.front();q.pop();
                for(int j=head[x];j;j=e[j].nxt){
                    int v=e[j].v;
                    if(!vis[v])cov[v]=1;
                    // 原图能到但暂未访问就标记可以去
                }
                for(int j=nx[0];j;j=nx[j]){
                    if(!cov[j]){
                        // 如果访问不到就入队
                        vis[j]=1;kuai[ans]++;
                        // 在补图里面访问过了 加入块里 删掉
                        dele(j);
                        q.push(j);
                    }
                    else cov[j]=0;
                    // 能原图访问到就算了
                }
            }
        }
    }
    sort(kuai+1,kuai+ans+1);
    printf("%d\n",ans);
    for(int i=1;i<=ans;i++){
        printf("%d ",kuai[i]);
    }
    system("pause");
}