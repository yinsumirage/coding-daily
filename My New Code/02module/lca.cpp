//LCA least common ancestors
#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int edge[N];
int nest[N];
int last[500010];
int cnt=1;

inline void add(int u,int v){
	nest[cnt]=last[u];
	edge[cnt]=v;
	last[u]=cnt;
	cnt++;
	return;
}
//用来保存父节点 
int dp[500010][20];
//保存深度 
int depth[500010]; 
//预处理出父亲切点 
bool vise[500010];
void DFS(int k){
	//预处理出DP数组
	for(int i=1;(1<<i)<depth[k];i++){
		dp[k][i]=dp[dp[k][i-1]][i-1];
	}
	for(int i=last[k];i;i=nest[i]){
		//求解直接公共祖先；
		if(vise[edge[i]])continue;
		vise[edge[i]]=true; 
		depth[edge[i]]=depth[k]+1;
		dp[edge[i]][0]=k;
		DFS(edge[i]);
	}
	return; 
} 
int lca(int u,int v){
	if(depth[u]<depth[v])swap(u,v);
	//弹节点 
	int k=log2(depth[u]-depth[v]);
	for(int i=k;i>=0;i--){
		if(depth[dp[u][i]]>=depth[v])u=dp[u][i];
	} 
	if(u==v)return u;
	//查询
	k=log2(depth[u]);
	for(int i=k;i>=0;i--){
		if(dp[u][i]==dp[v][i])continue;
		u=dp[u][i];
		v=dp[v][i];
	} 
	return dp[u][0];
}
int main(){
	//LCA模板题
	int n,m,s;
	cin>>n>>m>>s;
	int u,v;
	for(int i=0;i<n-1;i++){
		scanf("%d %d",&u,&v);
		add(u,v);
		add(v,u);
	} 
	//这里要初始化为1，避免与深度为0的0产生歧义。 
	depth[s]=1;
	vise[s]=true;
	DFS(s);
	for(int i=0;i<m;i++){
		scanf("%d %d",&u,&v);
		cout<<lca(u,v)<<endl;
	}
	return 0;
	
}