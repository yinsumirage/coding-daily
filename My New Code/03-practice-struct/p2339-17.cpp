#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=0x3f3f3f3f;
const int N = 1e3 + 50;

// 区间dp
// 最佳策略来自
// 1向左或向右移动到下个教室交作业
// 2从一个端点移动到另一个
// 如果先去中间教室 之后必然要走到i教室和j教室 那么不如先去i教室或者j教室
// 之后去另一端教室时必然会经过中间的教室交作业

// f[i][j][0]表示人在[i,j]左端点且区间[i+1,j]教室还没交作业
// f[i][j][1]表示人在[i,j]右端点且区间[i,j-1]教室还没交作业
// 更新的时候就是两边更新 
// 左边举例 要不由这里的a[i].t更新 要不由左边f[i-1][j][0]来这里
// 要不由右边f[i][j+1][1]端点来这里

int c,h,b;
int ans=INF;
int dp[N][N][2];

struct node{
    int x,t;
    bool operator < (const node &b)const {
        return x<b.x;
    }
}a[N];

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

signed main() {
    c=read();
    h=read();
    b=read();
    for(int i=1;i<=c;i++){
        a[i].x=read();
        a[i].t=read();
    }
    sort(a+1,a+c+1); // sort完从位置小到大排序
    memset(dp,INF,sizeof(dp));
    dp[1][c][0]=max(a[1].x,a[1].t);
    dp[1][c][1]=max(a[c].x,a[c].t);
    for(int i=1;i<=c;i++){
        for(int j=c;j>=i;j--){
            dp[i][j][0]=min(dp[i][j][0],max(dp[i-1][j][0]+a[i].x-a[i-1].x,a[i].t));
            dp[i][j][0]=min(dp[i][j][0],max(dp[i][j+1][1]+a[j+1].x-a[i].x,a[i].t));
            dp[i][j][1]=min(dp[i][j][1],max(dp[i][j+1][1]+a[j+1].x-a[j].x,a[j].t));
            dp[i][j][1]=min(dp[i][j][1],max(dp[i-1][j][0]+a[j].x-a[i-1].x,a[j].t));
        }
    }
    for(int i=1;i<=c;i++)
    ans=min(ans,min(dp[i][i][0]+abs(a[i].x-b),dp[i][i][1]+abs(a[i].x-b)));
    printf("%d\n",ans);
    system("pause");
}