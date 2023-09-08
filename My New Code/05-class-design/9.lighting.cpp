#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
ll ans=1e9;
int dxy[5][2]={{1,0},{-1,0},{0,-1},{0,1},{0,0}};
bool light[18][18];
bool add[18][18];
char sh[18];

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

int main(){
    n=read();m=read();
    for(int i=1;i<=n;i++){
        scanf("%s",sh);
        for(int j=1;j<=m;j++){
            light[i][j]=sh[j-1]-'0';
        }
    }
    for(ll s=0;s<(1<<m);s++){
        ll step=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                add[i][j]=0;
            }
        }
        for(ll i=0;i<m;i++){
            if((1ll<<i)&s){
                for(int k=0;k<5;k++){
                    add[1+dxy[k][0]][i+1+dxy[k][1]]^=1;
                }
                step++;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=m;j++){
                if(add[i][j]!=light[i][j]){
                    for(int k=0;k<5;k++){
                        add[i+1+dxy[k][0]][j+dxy[k][1]]^=1;
                    }
                    step++;
                }
            }
        }
        int ji=1;
        for(int j=1;j<=m;j++){
            if(add[n][j]!=light[n][j]){
                ji=0;
                step=0;
                break;
            }
        }
        if(ji)ans=min(ans,step);
    }
    printf("%lld\n",ans);
    system("pause");
}