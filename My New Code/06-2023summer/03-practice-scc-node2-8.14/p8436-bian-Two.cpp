#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 5e5 +5;
const int M = 5e6+5;

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

int n,m,cut[M],ans;
vector< vector <int> >Ans;

struct edge{
    int to,nxt;
}e[M];

int head[M],cnt=1;//!!!!!cnt要设成1，不然异或的时候会出问题

void add(int f, int t){
	e[++cnt].to = t;
	e[cnt].nxt = head[f];
	head[f] = cnt;
}

int dfn[N],low[N],dfncnt;
int dcc[N],ndcc;

void tarjan(int node, int in_edge)
{
	dfn[node] = low[node] = ++dfncnt;
	for (int i = head[node]; i; i = e[i].nxt)
	{
		const int to = e[i].to;
		if (dfn[to] == 0)
		{
			tarjan(to, i);
			if (dfn[node] < low[to])
				cut[i] = cut[i ^ 1] = 1;
			low[node] = min(low[node], low[to]);
		}
		else if (i != (in_edge ^ 1))
			low[node] = min(low[node], dfn[to]);
	}
}
void dfs(int node, int ndcc)
{
	dcc[node] = ndcc;
	Ans[ndcc - 1].push_back(node);
	for (int i = head[node]; i; i = e[i].nxt)
	{
		int to = e[i].to;
		if (dcc[to] || cut[i]) continue;
		dfs(to, ndcc);
	}
}
int main()
{
	n=read(),m=read();
	for (int i = 1; i <= m; ++i)
	{
		int u=read(),v=read();
		if (u == v) continue;
		add(u, v);
		add(v, u);
	}
	for (int i = 1; i <= n; ++i)
		if (dfn[i] == 0)
			tarjan(i, 0);
	for (int i = 1; i <= n; ++i)
		if (dcc[i] == 0)
		{
			Ans.push_back(vector <int>());
			dfs(i, ++ans);
		}
	printf("%d\n", ans);
	for (int i = 0; i < ans; ++i)
	{
		printf("%d", Ans[i].size());
		for (int j = 0; j < Ans[i].size(); ++j)
			printf(" %d", Ans[i][j]);
		printf("\n");
	}
	system("pause");
}