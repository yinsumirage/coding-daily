#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=0x3f3f3f3f;
const int N = 1e4 + 5;

int day[14]={0,31,59,90,120,151,181,212,243,273,304,334};
int n,x;
double dp[366];

struct tou{
    int st;
    int len;
    double c;
    bool operator < (const tou c)const{
        return st+len<c.st+c.len;
    }
}t[N];

signed main() {
    cin>>n;
    dp[1]=100000;
    for(int i=1;i<=n;i++){
        cin>>x;
        t[i].st=day[x/100-1]+x%100;
        cin>>t[i].len;
        cin>>t[i].c;
    }
    for(int i=2;i<=366;i++){
        dp[i]=dp[i-1];
        for(int j=1;j<=n;j++){
            if(t[j].st+t[j].len==i){
                dp[i]=max(dp[i],dp[t[j].st]*(1+(t[j].c/100)/365*t[j].len));
            }
        }
    }
    printf("%.2lf\n",dp[366]);
    system("pause");
}