#include<iostream>
#include<fstream>
using namespace std;
typedef long long ll;
int n,k;
int a[100][100]={0};
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
    for(int i=1;i<=30;i++){
        for(int j=1;j<=20;j++){
            a[i][j]=read();
        }
    }
    printf("wall: {\n");
    for(int i=1;i<=30;i++){
        for(int j=1;i<=20;j++){
            if(a[i][j]!=0)printf("        [utils.asGridCoord(%d, %d)]: true,\n",i,j);
        }
    }
    printf("      }\n");
    system("pause");
}