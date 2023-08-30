#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

//改变数字变为单调上升的序列
//推出b[i]=a[i]-i 变成 求b的最长不下降子序列
//求b的最长不下降子序列有经典的 O(nlogn) 方法

int a[40005],b[40005];
int mini[40005],f[40005];
ll g[40005],pre[40005],suf[40005];
//pre 是前面 suf 是后面
// 中间不合理的部分，前面变成pre 后面变为suf
// g[i]最后一位为b[i]时的不降代价

vector<int> recordends[40005]; //记录长度为i的最长不降子序列

//第二问 对于区间[l,r]使其单调不降 则存在分界点k 使得bi=bl bj=br(i<=k j>k)

int main() {
    fastio;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i]-i;
    }
    b[n+1]=1e9;
    b[0]=-1e9;
    int len=0;
    for(int i=1;i<=n+1;i++){
        int l=0,r=len;
        while(l<r){//从左到右遍历数组
            int mid=(l+r+1)/2;  
            if(mini[mid]<=b[i])l=mid;
            else r=mid-1;
        }
        if(l==len)len++;
        f[i]=l+1; 
        mini[l+1]=b[i];
        recordends[f[i]].push_back(i);//记录长度为f[i]的最长不降子序列结尾
    }
    printf("%d\n",n-len+1);
    recordends[0].push_back(0);
    memset(g,20,sizeof(g));
    g[0]=0;
    for(int i=1;i<=n+1;i++){  
        for(int j=0,size=recordends[f[i]-1].size();j<size;j++){
            int from=recordends[f[i]-1][j]; //遍历到
            if(from>i||b[from]>b[i])continue; 
            pre[from]=suf[i-1]=0; //边界
            for(int k=from+1;k<=i-1;k++){ //i作为中间点 分别求前后缀
                pre[k]=pre[k-1]+abs(b[k]-b[from]);
            }
            for(int k=i-2;k>=from;k--){ //注意=号 要取到前列
                suf[k]=suf[k+1]+abs(b[k+1]-b[i]);
            }
            for(int k=from;k<=i-1;k++){
                g[i]=min(g[i],g[from]+pre[k]+suf[k]);
            }
        }
    }
    printf("%lld\n",g[n+1]);
    system("pause");
    return 0;
}