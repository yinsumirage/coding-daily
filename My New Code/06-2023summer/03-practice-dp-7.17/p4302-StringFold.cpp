#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)

string s;
int n;
int f[105][105];
int wei[105]; //位数会改变长度大小，10个就是两个字符串了


//区间dp题  用f i表示i-j这个区间内的最小的长度
//将i-j这个区间的字符串拆成两段处理

bool checkit(int le,int zho,int len){
    for(int i=le;i<=zho;i++){
        if(s[i]!=s[(i-le)%len+le])return false;
    }
    return true;
}

int main() {
    cin>>s;
    n=s.size();  //要记住这里是算大小 再在前面加空格
    s=' '+s;


    for(int i=1;i<=9;i++)wei[i]=1;
    for(int i=10;i<=99;i++)wei[i]=2;
    wei[100]=3;

    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++)f[i][i]=1; 

    for(int l=2;l<=n;l++){  //大的区间
        for(int i=1,j=i+l-1;j<=n;i++,j++){
            for(int k=i;k<j;k++){   //区间dp
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]); 
            }
            for(int k=i;k<j;k++){  //检查本区间能否折叠
                int len=k-i+1;
                if(l%len!=0)continue;
                if(checkit(i,j,len)){
                    f[i][j]=min(f[i][j],f[i][k]+2+wei[l/len]);
                }
            }
        }
    }
    printf("%d",f[1][n]);
    system("pause");
    return 0;
}