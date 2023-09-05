#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

int n;
double sum;
vector<pair<ll,int>>v;

ll a[1001];

ll read(){
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
    fastio;
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        v.push_back({a[i],i});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        printf("%d ",v[i].second);
        sum+=v[i].first*(n-i-1);
    }
    sum/=(double)n;
    printf("\n%.2lf",sum);
    //system("pause");
}