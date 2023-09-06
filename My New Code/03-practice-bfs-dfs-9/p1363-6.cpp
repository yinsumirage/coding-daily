#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1520;

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

int n,m;
char a[N][N];
bool vis[2*N][2*N];
bool v[N][N];
int sh,sl;

struct node{
    int h,l;
};

queue<node>q;
int dh[4]={0,0,1,-1};
int dl[4]={1,-1,0,0};

bool dfs(int h,int l){
    if(h==-1)return dfs(2*n-1,l);
    if(h==n*2)return dfs(0,l);
    if(l==-1)return dfs(h,2*m-1);
    if(l==m*2)return dfs(h,0);
    if(vis[h][l]||a[h%n][l%m]=='#')return false;
    if(v[h%n][l%m])return true;
    v[h%n][l%m]=vis[h][l]=1;
    for(int i=0;i<4;i++)if(dfs(h+dh[i],l+dl[i]))return true;
    return false;
}


signed main() {
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    while(scanf("%d %d",&n,&m)!=EOF){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
                if(a[i][j]=='S'){
                    sh=i;sl=j;
                }
            }
        }
        memset(v,0,sizeof(v));
        memset(vis,0,sizeof(vis));
        if(dfs(sh,sl))printf("Yes\n");
        else printf("No\n");
    }
    system("pause");
}