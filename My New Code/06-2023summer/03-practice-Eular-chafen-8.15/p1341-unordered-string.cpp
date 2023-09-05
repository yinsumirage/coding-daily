#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

int n,k=100,cnt=0,tot=0;
char s[2];
int e[100][100],du[100],a[100],c[N];

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

void dfs(int u){
    for(int i=0;i<58;i++){
        if(e[u][i]){
            e[u][i]=e[i][u]=0;
            dfs(i);
        }
    }
    c[++tot]=u; //储存欧拉回路
}

signed main() {
    //fastio;
    n=read();
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        int u=s[0]-'A';
        int v=s[1]-'A';
        k=min(k,min(u,v));
        e[u][v]=e[v][u]=1;
        du[u]++;du[v]++;
    }
    for(int i=0;i<58;i++){
        if(du[i]%2==1){
            cnt++;
            a[cnt]=i;
        }
    }
    if(cnt==0)dfs(k);
    else if(cnt==2)dfs(a[1]);
    else {
        printf("No Solution\n");
        return 0;
    }
    for(int i=tot;i>=1;i--)printf("%c",c[i]+'A');
    system("pause");
}