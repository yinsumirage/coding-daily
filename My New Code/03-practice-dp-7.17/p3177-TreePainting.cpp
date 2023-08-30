#include <bits/stdc++.h>
using namespace std;
#define re register
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 2005;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

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
//计算距离——换根dp做到O(n)
//反过来思考 先计算完所有点之间的距离 再减去有黑白颜色差异的点
// 将差异点带来的值称为贡献度 目标转化为最小化贡献值

//重要思想(大佬asuldb题解)
//差分
// 将贡献值用差分思想 转化为了 s*其父亲边长度 s[i]是i这个子树内部白点数

struct node{
    int w,to,next;
}way[N<<1];

int tot=0,n,k;
int sum[N],dep[N],head[N];
ll dp[N][N],f[N],tf[N],pre[N];
// 根路径距离tf  路径权值前缀和pre
//i为根的子树里染j个白点的最小贡献是多少

//建树要好好学习才能掌握好
void add(int x,int y,int z){
    way[++tot].w=z;  //权值
    way[tot].to=y;   //下个节点
    way[tot].next=head[x];//作指针
    head[x]=tot; 
}

void dfs(int x){
    sum[x]=1;
    for(int i=head[x];i;i=way[i].next){
        if(!dep[way[i].to]){
            dep[way[i].to]=dep[x]+1; //计算本点的深度
            tf[way[i].to]=way[i].w;  //记录每一点前面的路径的权值
            pre[way[i].to]=pre[x]+way[i].w; //权值前缀和
            dfs(way[i].to); //向深处递推
            sum[x]+=sum[way[i].to]; //反向回来记录总值 记录的子树中的节点数
            f[x]+=f[way[i].to];     
            f[x]+=sum[way[i].to]*way[i].w; //字数节点数*权值=目标
        }
    }
}
void down(int x){
    for(int i=head[x];i;i=way[i].next){
        if(dep[way[i].to]>dep[x]){//向下搜索 去更深的地方
            f[way[i].to]+=f[x]-f[way[i].to]-sum[way[i].to]*way[i].w;
            // f[x]中有各个子节点中的和 现在只减去本节点 保留其余节点
            f[way[i].to]+=(n-sum[x])*way[i].w;
            down(way[i].to);
        }
    }
}
void Redfs(int x){
    dp[x][1]=-1*(ll)k*pre[x];
    dp[x][0]=-1*(ll)(n-k)*pre[x];
    for(int i=head[x];i;i=way[i].next){
        if(dep[way[i].to]>dep[x]){
            Redfs(way[i].to);
            for(int j=min(n-k,sum[x]);j>=0;j--){
                ll mid=-9893849389343;
                for(int p=0;p<=j;p++){
                    mid=max(mid,dp[way[i].to][p]+dp[x][j-p]);
                }
                dp[x][j]=mid;
            }
        }
        for(int j=0;j<=min(n-k,sum[x]);j++){
            dp[x][j]+=2*tf[x]*j*(sum[x]-j);
        }
    }

}

int main() {
    n=read();
    k=read();
    for(int i=1,u,v,w;i<n;i++){
        u=read(),v=read(),w=read();
        add(u,v,w);
        add(v,u,w);
    }
    dep[1]=1;
    dfs(1);
    down(1);
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=f[i];
    }
    ans>>=1ll;
    if(!k){
        printf("%lld\n",ans);
        return 0;
    }
    memset(dp,-20,sizeof(dp));
    Redfs(1);
    ans+=dp[1][n-k];
    printf("%lld\n",ans);
    system("pause");
    return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<cstring>
#define re register
#define maxn 2005
#define LL long long
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
struct E
{
	int v,nxt,w;
}e[maxn<<1];
int n,num,K;
int sum[maxn],head[maxn],deep[maxn];
LL f[maxn],pre[maxn],dp[maxn][maxn],tf[maxn];
inline void add_edge(int x,int y,int z)
{
	e[++num].v=y;
	e[num].nxt=head[x];
	e[num].w=z;
	head[x]=num;
}
inline int read()
{
	char c=getchar();
	int x=0;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9')
		x=(x<<3)+(x<<1)+c-48,c=getchar();
	return x;
}
void dfs(int x)
{
	sum[x]=1;
	for(re int i=head[x];i;i=e[i].nxt)
	if(!deep[e[i].v])
	{
		deep[e[i].v]=deep[x]+1;
		tf[e[i].v]=e[i].w;
        pre[e[i].v]=pre[x]+e[i].w;
		dfs(e[i].v);
		sum[x]+=sum[e[i].v];
		f[x]+=f[e[i].v];
        f[x]+=sum[e[i].v]*e[i].w;
	}
}
void down(int x)
{
	for(re int i=head[x];i;i=e[i].nxt)
	if(deep[e[i].v]>deep[x])
	{
		f[e[i].v]+=f[x]-f[e[i].v]-sum[e[i].v]*e[i].w;
		f[e[i].v]+=(n-sum[e[i].v])*e[i].w;
		down(e[i].v);
	}
}
void Redfs(int x)
{
	dp[x][1]=-1*(LL)K*pre[x];
    dp[x][0]=-1*(LL)(n-K)*pre[x];
	for(re int i=head[x];i;i=e[i].nxt)
	if(deep[e[i].v]>deep[x])
	{
		Redfs(e[i].v);
		for(re int j=min(n-K,sum[x]);j>=0;j--)
		{
			LL mid=-9893849389343;
			for(re int p=0;p<=j;p++)
				mid=max(mid,dp[x][j-p]+dp[e[i].v][p]);
            //树上背包合并，这里将贡献值取反了，于是需要求最大值
			dp[x][j]=mid;
		}
	}
	for(re int j=0;j<=min(n-K,sum[x]);j++)
		dp[x][j]+=2*tf[x]*j*(sum[x]-j);
}
int main()
{
	n=read(),K=read();
	int x,y,z;
	for(re int i=1;i<n;i++) 
		x=read(),y=read(),z=read(),add_edge(x,y,z),add_edge(y,x,z);
	deep[1]=1,dfs(1),down(1);//先换根dp求一下总答案
	LL ans=0;
	for(re int i=1;i<=n;i++)
		ans+=f[i];//f[i]表示所有点到点i的距离和
	ans>>=1ll;
	if(!K)
	{
		std::cout<<ans;
		return 0;
	}
	memset(dp,-20,sizeof(dp));
	Redfs(1);
	ans+=dp[1][n-K];
	std::cout<<ans;
    system("pause");
	return 0;
}
*/