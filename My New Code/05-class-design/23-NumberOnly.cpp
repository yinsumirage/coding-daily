#include<iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 5;

int n,t,sum1,sum2;
int a[17][17],b[17][17],chang[5];// b 备份 chang 换列的时候的变
bool righ;
int rotnum[5][5],check[17],li[17];
char tmp[5][5];

void rot(int x,int y){
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            tmp[5-i][j]=a[j+(x-1)*4][i+(y-1)*4];
        }
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            a[i+(x-1)*4][j+(y-1)*4]=tmp[i][j];
        }
    }
}

void returning(int x,int y){
    for(int i=1;i<=4;i++)for(int j=1;j<=4;j++)
        a[i+(x-1)*4][j+(y-1)*4]=b[i+(x-1)*4][j+(y-1)*4];
    rotnum[x][y]=0;
}

bool okh(int x){
    for(int i=1;i<=16;i++)check[a[x][i]]++;
    for(int i=1;i<=16;i++){
        if(check[i]!=1){
            for(int i=1;i<=16;i++)check[i]=0;
            return 0;
        }
    }
    for(int i=1;i<=16;i++)check[i]=0;
    return 1;
}

void dfs(int u,int v){
    if(righ==1)return;
    if(v==4){
        for(int i=0;i<4;i++){
            for(int j=1;j<=i;j++)rot(u,v);
            rotnum[u][v]=i;
            if(okh(u*4)){righ=1;return;}
            else returning(u,v);
        }
    }
    else {
        for(int i=0;i<4;i++){
            for(int j=1;j<=i;j++)rot(u,v);
            rotnum[u][v]=i;
            dfs(u,v+1);
            if(okh(u*4)){righ=1;return;}
            else returning(u,v);
        }
    }
}

bool okli(){
    for(int i=1;i<=16;i++)check[li[i]]++;
    for(int i=1;i<=16;i++){
        if(check[i]!=1){
            for(int i=1;i<=16;i++)check[i]=0;
            return 0;
        }
    }
    for(int i=1;i<=16;i++)check[i]=0;
    return 1;
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

int main(){
    t=read();
    while(t--){
        for(int i=1;i<=16;i++){
            for(int j=1;j<=16;j++){
                char c=getchar();
                if(c>='0'&&c<='9')b[i][j]=a[i][j]=c-47;
                else b[i][j]=a[i][j]=c-54;
            }
            getchar();
        }
        for(int i=1;i<=4;i++){righ=0;dfs(i,1);}
        for(int i=15;i>=0;i--){
            for(int j=0;j<4;j++){
                if((1<<j)&i){
                    for(int k=4*j+1;k<=4*(j+1);k++)li[k]=a[k][1];
                    chang[j+1]=0;
                }
                else{
                    for(int k=4*j+1;k<=4*(j+1);k++)li[k]=a[k][4];
                    chang[j+1]=1;
                }
            }
            if(okli())break;
        }
        for(int i=1;i<=4;i++)if(chang[i])for(int j=1;j<=4;j++)rotnum[i][j]=(rotnum[i][j]+2)%4;
        sum1=sum2=0;
        for(int i=1;i<=4;i++)for(int j=1;j<=4;j++){
            sum1+=rotnum[i][j];sum2+=(rotnum[i][j]+2)%4;
        }
        if(sum1>sum2){
            printf("%d\n",sum2);
            for(int i=1;i<=4;i++)for(int j=1;j<=4;j++)for(int k=1;k<=(rotnum[i][j]+2)%4;k++)printf("%d %d\n",i,j);
        }
        else{
            printf("%d\n",sum1);
            for(int i=1;i<=4;i++)for(int j=1;j<=4;j++)for(int k=1;k<=rotnum[i][j];k++)printf("%d %d\n",i,j);
        }
    }
    system("pause");
}