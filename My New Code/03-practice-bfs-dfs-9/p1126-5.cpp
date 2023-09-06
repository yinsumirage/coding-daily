#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=0x3f3f3f3f;
const int N = 1e6 + 5;

int n,m,a[55][55],vis[55][55][5],si,sj,ei,ej;
int b[55][55];
int chao;
char mian;
int dj[5]={0,0,0,-1,1};
int di[5]={0,-1,1,0,0};


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

struct run{
    int h,l,t;
    int m;
    run(int xx,int yy,int zz,int kk){
        h=xx,l=yy,m=zz,t=kk;
    }
};

queue<run>q;

signed main() {
    //fastio;
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]=read()){
                b[i][j]=b[i-1][j-1]=b[i-1][j]=b[i][j-1]=1;
            }
        }
    }
    // for(int i=1;i<n;i++){
    //     for(int j=1;j<m;j++){
    //         printf("%d ",b[i][j]);
    //     }
    //     printf("\n");
    // }
    si=read();sj=read();ei=read();ej=read();
    if(si==ei&&sj==ej){
        printf("0\n");return 0;
    }
    if(b[si][sj]==1){
        printf("-1\n");return 0;
    }
    mian=getchar();
    switch (mian){
    case 'N' :chao=1;break;
    case 'S' :chao=2;break;
    case 'W' :chao=3;break;
    case 'E' :chao=4;break;
    }
    vis[si][sj][chao]=1;
    q.push(run(si,sj,chao,0));
    while(!q.empty()){
        run u=q.front();q.pop();
        int hh=u.h,ll=u.l,ch=u.m,tt=u.t+1;
        if(ch>=3){
            if(!vis[hh][ll][1]){
                q.push(run(hh,ll,1,tt));
                vis[hh][ll][1]=1;
            }
            if(!vis[hh][ll][2]){
                q.push(run(hh,ll,2,tt));
                vis[hh][ll][1]=1;
            }
        }
        else {
            if(!vis[hh][ll][3]){
                q.push(run(hh,ll,3,tt));
                vis[hh][ll][3]=1;
            }
            if(!vis[hh][ll][4]){
                q.push(run(hh,ll,4,tt));
                vis[hh][ll][4]=1;
            }
        }
        for(int i=1;i<=3;i++){
            hh+=di[ch];ll+=dj[ch];
            if(hh>=n||hh<1||ll>=m||ll<1||b[hh][ll])break;
            if(vis[hh][ll][ch])continue;
            if(hh==ei&&ll==ej){
                printf("%d\n",tt);
                system("pause");
                return 0;
            }
            q.push(run(hh,ll,ch,tt));
            vis[hh][ll][ch]=1;
        }
    }
    printf("-1\n");
    system("pause");
}