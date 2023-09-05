#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
const int N = 1e4 + 5;


int sol[N][N]; // 第i个城堡，第j个人拍的兵数
int dp[20004];   //剩余j兵力，得到的最多分数

int main() {
    fastio;

    int s,n,m; //人数 城堡 士兵
    cin>>s>>n>>m;
    for(int i=1;i<=s;i++){
        for(int j=1;j<=n;j++){
            cin>>sol[j][i];
        }
    }
    for(int j=1;j<=n;j++){ //这个排序记住，二维的
        sort(sol[j]+1,sol[j]+s+1);
    }
    for(int i=1;i<=n;i++){ //城堡
        for(int j=m;j>=0;j--){ //士兵
            for(int k=1;k<=s;k++){ //每个人
                if(j>sol[i][k]*2){
                    dp[j]=max(dp[j-sol[i][k]*2-1]+k*i,dp[j]);
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<=m;i++){
        ans=max(ans,dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}