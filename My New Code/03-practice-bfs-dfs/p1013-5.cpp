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

int n,m;
char c;
char s[10][10][3];
int ans[10],buck[26];

bool che(int x,int y){
    int sum=ans[x]+ans[y];
    int now=s[x][y][1]-'A';
    if(sum>=n-1&&buck[now]!=1)return 0;
    if(sum>=n-1)sum-=n-1,now=s[x][y][2]-'A';
    if(buck[now]!=sum)return 0;
    return 1;
}

signed main() {
    //fastio;
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++)scanf("%s",s[1][i]+1);
    for(int i=2;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            scanf("%s",s[i][j]+1);
            cnt+=strlen(s[i][j]+1)>=2;
        }
        ans[i]=cnt;
        buck[s[i][1][1]-'A']=cnt;
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j<=n;j++){
            if(!che(i,j))return 0&printf("%s","ERROR!\n");
        }
    }
    for(int i=2;i<=n;i++)printf("%c=%d ",s[i][1][1],ans[i]);
    printf("\n%d\n",n-1);
    system("pause");
}