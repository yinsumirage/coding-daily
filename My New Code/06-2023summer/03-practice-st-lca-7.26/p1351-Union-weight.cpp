#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define fup(i,j,k) for(i=j;i<=k;++i)
#define fdo(i,j,k) for(i=j;i>=k;--i)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 2e5 + 5;

// 联合权值
// 联合的两个节点距离为2 必定有中转点，枚举中转点即可
// 以某个节点为中转点的联合权值为，全部权值和的平方减去权值的平方和

int i,j,l,r,mod=10007,maxx=0,ans=0;
ll n,m;
int cnt;
int head[N],w[N];
struct edge{
    int v,nxt;
}e[N*2];

void add(int u,int v){
    e[++cnt].v=v;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}

inline ll read(){
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
    fastio;
    n=read();
    fup(i,1,n-1){
        int u,v;
        u=read(),v=read();
        add(u,v);
        add(v,u);
    }
    fup(i,1,n){
        w[i]=read();
    }
    fup(i,1,n){
        int ma1=0,ma2=0; //最大的两个权值
        int s1=0,s2=0;   //s1和的平方，s2平方和
        for(j=head[i];j;j=e[j].nxt){
            int v=e[j].v;
            if(w[v]>ma1)ma2=ma1,ma1=w[v];
            else if(w[v]>ma2)ma2=w[v];
            s1=(s1+w[v])%mod;
            s2=(s2+w[v]*w[v])%mod;
        }
        s1=s1*s1%mod;
        ans=(ans+s1-s2+mod)%mod;
        if(maxx<ma1*ma2)maxx=ma1*ma2;
    }
    printf("%d %d\n",maxx,ans);
    system("pause");
}