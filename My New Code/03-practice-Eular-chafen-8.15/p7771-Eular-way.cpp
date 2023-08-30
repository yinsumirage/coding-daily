#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

vector<int> E[N];
int n,m;
int du[N][2];
int del[N];
//del[now]表示E[now][1,2,···,del[now]-1]都被访问
int sk[N],top;

void dfs(int now){
    for(int i=del[now];i<E[now].size();i=del[now]){
        del[now]=i+1;
        dfs(E[now][i]);
    }
    sk[++top]=now;
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

int flag=1;
// 所有节点都出入度相同
int cnt[2],start=1;

signed main() {
    //fastio;
    n=read();
    m=read();
    for(int i=1;i<=m;i++){
        int u=read(),v=read();
        E[u].push_back(v);
        du[v][0]++; //入度
        du[u][1]++; //出度
    }
    for(int i=1;i<=n;i++){
        sort(E[i].begin(),E[i].end());
    }
    for(int i=1;i<=n;i++){
        if(du[i][1]!=du[i][0]){
            flag=0;
            if(du[i][1]-du[i][0]==1)cnt[1]++,start=i;
            else if(du[i][0]-du[i][1]==1)cnt[0]++;
            else {
                printf("No");
                return 0;
            }
        }
    }
    if((flag==0)&&!(cnt[0]==cnt[1]&&cnt[0]==1)){
        printf("No");
        return 0;
    }
    dfs(start);
    for(int i=m+1;i>0;i--)printf("%d ",sk[i]);
    system("pause");
}