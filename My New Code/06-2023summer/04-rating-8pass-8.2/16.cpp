#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N= 1e5+5;
const int INF=0x3f3f3f3f;

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

struct edge{
	ll v,nxt,w,t1,t2;
}e[N*15];

ll n,m,head[N*15],dp[N*15],vis[N*15],cnt=0;

void add(int u,int v,int w,int t1,int t2){
	e[++cnt].v=v;
	e[cnt].nxt=head[u];
	e[cnt].t1=t1;
	e[cnt].t2=t2;
	e[cnt].w=w;
	head[u]=cnt;
}

void dij(){
	memset(vis,0,sizeof(vis));
	priority_queue< pair<int,int> > q;
	q.push({0,1});
	while(!q.empty()){
		pair<int,int> p1=q.top();
		q.pop();
		int u=p1.second;
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].v;
			if(dp[u]>=e[i].t1&&dp[u]<=e[i].t2){
				if(dp[v]>e[i].w+e[i].t2){
					dp[v]=e[i].w+e[i].t2;
					q.push({dp[v],v});
				}
			}
			else if(dp[v]>dp[u]+e[i].w){
				dp[v]=dp[u]+e[i].w;
				q.push({dp[v],v});
			}
		}
	}
}

int main(){
	n=read();m=read();
	int u,v,w,l,r;
	for(int i=1;i<=m;i++){
		u=read();
		v=read();
		w=read();
		l=read();
		r=read();
		add(u,v,w,l,r);
		add(v,u,w,l,r);
		for(int j=1;j<=2;j++){
			add(u+(j-1)*n,v+j*n,0,0,0);
			add(v+(j-1)*n,u+j*n,0,0,0);
			add(u+j*n,v+j*n,w,l,r);
			add(v+j*n,u+j*n,w,l,r);
		}
	}
	memset(dp,0x3f,sizeof(dp));
	dp[1]=0;
	add(1,1+n,0,0,0);
	add(1+n,1+2*n,0,0,0);
	add(n,2*n,0,0,0);
	add(2*n,3*n,0,0,0);
	dij();	
	for(int j=0;j<=2;j++){
		for(int i=1;i<=n;i++){
			printf("%lld ",dp[i+j*n]);
		}
		printf("\n");
	}
	printf("%lld",dp[n*3]);
	return 0;
}

