#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 5005;

int n,m,cnt=0,s;
int head[N],tot[N],dis[N],vis[N];

struct edge{
    int v,w,nxt;
}e[N*4];

void add(int u,int v,int w){
    e[++cnt].w=w;
    e[cnt].v=v;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}

bool spfa(int s){
    queue<int> q;
    memset(dis,63,sizeof(dis));
    dis[s]=0;vis[s]=1;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v;
            if(dis[v]>dis[u]+e[i].w){
                dis[v]=dis[u]+e[i].w;
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                    tot[v]++;
                    if(tot[v]==n+1)return false;
                }
            }
        }
    }
    return true;
}

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

signed main() {
    fastio;
    n=read();m=read();
    for(int i=1,op,a,b,c;i<=m;i++){
        op=read();a=read();b=read();
        if(op==1){
            c=read();
            add(a,b,-c);
        }
        else if(op==2){
            c=read();
            add(b,a,c);
        }
        else {
            add(a,b,0);
            add(b,a,0);
        }
    }
    s=0;
    for(int i=1;i<=n;i++)add(s,i,0);
    if(spfa(s))printf("Yes");
    else printf("No");
    //system("pause");
}

// AC 码
// #include<iostream>
// #include<queue>
// using namespace std;
// const int N=5005;
// struct edge
// {
// 	int to,nxt,v;
// }e[4*N];
// int n,m,cnt;
// int head[N],dis[N],tot[N],v[N];
// void add(int u,int v,int w)
// {
// 	cnt++;
// 	e[cnt].to=v;
// 	e[cnt].v=w;
// 	e[cnt].nxt=head[u];
// 	head[u]=cnt;
// }
// bool spfa()
// {
// 	queue<int> q;
// 	for(int i=1;i<=n;i++)
// 	dis[i]=2e9;
// 	q.push(0);
// 	v[0]=1;
// 	while(!q.empty())
// 	{
// 		int now=q.front();q.pop();
// 		v[now]=0;
// 		for(int i=head[now];i;i=e[i].nxt)
// 		{
// 			if(dis[e[i].to]>dis[now]+e[i].v)
// 			{
// 				dis[e[i].to]=dis[now]+e[i].v;
// 				if(!v[e[i].to])
// 				{
// 					v[e[i].to]=1;
// 					tot[e[i].to]++;
// 					if(tot[e[i].to]==n) return 0;
// 					q.push(e[i].to);
// 				}
// 			}
// 		}
// 	}
// 	return 1;
// }
// int main()
// {
// 	cin>>n>>m;
// 	for(int i=1;i<=n;i++)
// 	add(0,i,0);
// 	for(int i=1;i<=m;i++)
// 	{
// 		int op,a,b,c;
// 		cin>>op>>a>>b;
// 		if(op==1)
// 		{
// 			cin>>c;
// 			add(a,b,-c);
// 		}
// 		if(op==2)
// 		{
// 			cin>>c;
// 			add(b,a,c);
// 		}
// 		if(op==3)
// 		{
// 			add(a,b,0);
// 			add(b,a,0);
// 		}
// 	}
// 	cout<<(spfa()?"Yes":"No");
// 	return 0;
// }