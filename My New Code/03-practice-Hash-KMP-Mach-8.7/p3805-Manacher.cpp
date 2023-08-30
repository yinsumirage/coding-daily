#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e7 + 1e6+5;

int n,m;
int ans=0;
int d1[N*2];
char s[N],ss[N*2];

inline ll read(){
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
    cin>>s;
    n=strlen(s);
    for(int i=0;i<n;i++){
        ss[i*2]='#';
        ss[i*2+1]=s[i];
    }
    ss[2*n]='#';
    n=2*n+1;
    for(int i=0,l=0,r=-1;i<n;i++){
        int k=(i>r)?1:min(d1[l+r-i],r-i+1);
        while(i-k>=0&&i+k<n&&ss[i-k]==ss[i+k])k++;
        d1[i]=k--;
        if(i+k>r){
            l=i-k;r=i+k;
        }
    }
    for(int i=0;i<n;i++){
        ans=max(ans,d1[i]-1);
    }
    printf("%lld",ans);
    //system("pause");
}