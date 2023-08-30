#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;

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

int n,m,s,cnt,b;
int ans=1e9;
int dis[10005],head[10005],vis[10005],f[10005];
//dis距离  vis是否到过
priority_queue<pair<int,int>> q;

struct node{
    int w,to,next;
}way[100005];

inline void add(int u,int v,int w){
    cnt++;
    way[cnt].w=w;
    way[cnt].to=v;
    way[cnt].next=head[u];
    head[u]=cnt;
}

inline bool check(int x){ //对每个最大收费确定能否到达
    if(x<f[1])return 0;
    for(int i=1;i<=n;i++){
        dis[i]=1e9;
    }
    dis[1]=0;
    memset(vis,0,sizeof(vis));
    q.push({0,1});
    while(!q.empty()){
        pii p1=q.top();
        q.pop();
        int u=p1.second; //记录堆顶，最小的边，并弹出
        if(vis[u])continue;
        vis[u]=1;
        for(int i=head[u];i;i=way[i].next){
            int v=way[i].to;
            if(f[v]>x)continue;
            if(dis[v]>dis[u]+way[i].w){
                dis[v]=dis[u]+way[i].w;
                q.push({dis[v],v});
            }
        }
    }
    if(dis[n]<=b)return 1;
    return 0;
}


signed main() {
    n=read(),m=read(),b=read();
    for(int i=1;i<=n;i++)f[i]=read();
    for(int i=1,a,b,c;i<=n;i++){
        a=read(),b=read(),c=read();
        add(a,b,c);
        add(b,a,c);
    }
    if(check(ans)==0){
        printf("AFK/n");
        return 0;
    }
    int l=1,r=ans,mid=(l+r)>>1;
    while(l<=r){
        if(check(mid))r=mid-1;
        else l=mid+1;
        mid=(l+r)>>1;
    }

    printf("%d\n",l);
    //system("pause");
}


// AC 码
// #include<iostream>
// #include<cstdio>
// #include<algorithm>
// #include<queue> 
// #include<cstring>
// #define il inline
// #define rg register
// #define N 10005
// #define M 100005
// #define MAXN 1000000005//最大收费（二分用 
// using namespace std;
// int f[N];//每个城市的收费额度
// bool ed[N];//求最短路使用
// int dis[N];//同上
// int head[N];//前向星 
// priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > que;
// int n,m,b;
// int t;
// struct edge{
// 	int to,next,len;
// }e[M];
// il void add(int x,int y,int z){
// 	e[++t].len=z;
// 	e[t].to=y;
// 	e[t].next=head[x];
// 	head[x]=t;
// }
// il int read(){
// 	int sum=0;char a=getchar();
// 	while(a<'0'||a>'9')a=getchar();
// 	while(a>='0'&&a<='9'){
// 		sum=(sum<<3)+(sum<<1)+a-'0';
// 		a=getchar();
// 	}
// 	return sum;
// }
// il bool work(int x){//对于每个最大收费都确定是否可以到达 
//    if(x<f[1])return 0;//起点都过不了走个p 
// 	for(int i=1;i<=n;i++){
// 		dis[i]=1e9;//初始化为极大值 
// 	}
// 	memset(ed,0,sizeof(ed));
// 	dis[1]=0;
// 	que.push(make_pair(0,1));
// 	int s1,s2;
// 	while(que.size()){
// 		s1=que.top().second;que.pop();
// 		if(ed[s1])continue;
// 		ed[s1]=1;
// 		s2=head[s1];
// 		while(s2){//只有收费小于x的才能使用，大于x的一律视为没有 
// 			if(f[e[s2].to]<=x&&ed[e[s2].to]==0&&dis[s1]+e[s2].len<dis[e[s2].to])
// 			{dis[e[s2].to]=dis[s1]+e[s2].len;
// 			que.push(make_pair(dis[e[s2].to],e[s2].to));}//入堆准备下一轮操作 
// 			s2=e[s2].next;//去下一条边 
// 		}
// 	}
// 	if(dis[n]<b){
// 		return 1;
// 	}
// 	return 0;
// }
// int main(){
// 	n=read();m=read();b=read();
// 	for(rg int i=1;i<=n;i++)
// 	f[i]=read();//储存费用
// 	int a1,a2,a3;
// 	for(rg int i=1;i<=m;i++){
// 		a1=read();a2=read();a3=read();
// 		add(a1,a2,a3);
// 		add(a2,a1,a3);
// 	}
// 	if(work(MAXN)==0){
// 		cout<<"AFK"<<endl;
// 		return 0;//如果所有都开通任然不满足条件，剩下的肯定也不会满足 
// 	} 
// 	int l=1,r=MAXN,mid=(l+r)>>1;//准备开始二分
//  	int c;
//  	while(l<=r){
//  		c=work(mid);
//  		if(c){//如果可以的话 
//  			r=mid-1;
//  			mid=(l+r)>>1;
// 		 }
//  		else{
//  			l=mid+1;
//  			mid=(l+r)>>1;
// 		 }
// 	 }
// 	 cout<<l<<endl;
// }