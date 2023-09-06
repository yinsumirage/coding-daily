#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=0x3f3f3f3f;
const int N = 55;

int g[1005];
int n,m,sh,sl,t;
char a[N][N];
char mian[5];
int dh[5]={0,-1,1,0,0};
int dl[5]={0,0,0,-1,1};

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

struct node{
    int h,l,f;
};

queue<node> q;

int vis[55][55][4];

signed main() {
    //fastio;
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if((a[i][j]=getchar())=='*'){
                sh=i;sl=j;a[i][j]='.';
            }
        }
        getchar();
    }
    t=read();
    for(int i=1;i<=t;i++){
        scanf("%s",mian);
        switch (mian[0]){
        case 'N': g[i]=1;break;
        case 'S': g[i]=2;break;
        case 'W': g[i]=3;break;
        case 'E': g[i]=4;break;
        }
    }
    q.push(node{sh,sl,1});
    while(!q.empty()){
        node u=q.front();q.pop();
        int hh=u.h,ll=u.l,ff=g[u.f];
        if(u.f==t+1){
            a[hh][ll]='*';
            continue;
        }
        while(1){
            hh+=dh[ff];ll+=dl[ff];
            if(hh<1||hh>n||ll<1||ll>m||a[hh][ll]=='X')break;
            if(vis[hh][ll][ff])continue;
            q.push(node{hh,ll,u.f+1});
            vis[hh][ll][ff]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
    system("pause");
}