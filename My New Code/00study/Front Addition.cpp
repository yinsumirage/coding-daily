#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int a[N][N];  //二维数组
int main(){
    int n,m,r,t,x,y,v;
    cin>>t>>r;
    n=m=r;
    for(int i=1;i<=t;i++){
        cin>>x>>y>>v;
        x++;y++;
        n=max(n,x);
        m=max(m,y);
        a[x][y]+=v;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        } //二维前缀和
    }
    int res=0;
    for(int i=r;i<=n;i++){
        for(int j=r;j<=m;j++){
            res=max(res,a[i][j]-a[i-r][j]-a[i][j-r]+a[i-r][j-r]);
        }
    }
    cout<<res<<endl;
}