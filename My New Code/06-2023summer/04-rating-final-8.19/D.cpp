#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 15;

int n,m;
int ans=0x3f3f3f3f;
set<int>a,d;
int b[N];

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
    //fastio;
    n=read();
    m=read();
    if(n>=m){ //让b数组里少一些
        for(int i=1;i<=n;i++){
            a.insert(read());
        }
        for(int i=1;i<=m;i++){
            b[i]=read();
        }
    }
    else {
        for(int i=1;i<=n;i++){
            b[i]=read();
        }
        for(int i=1;i<=m;i++){
            a.insert(read());
        }
    }
    if(m==1){
        printf("%d",n-1);
        return 0;
    }
    if(n==1){
        printf("%d",m-1);
        return 0;
    }
    if(n<m)swap(n,m);
    for(int i=1;i<=m;i++){
        auto c=a.find(b[i]);
        if(c==a.end()){
            d.insert(b[i]);
        }
        else a.erase(b[i]);
    }
    //a里面多一些，d里面少一些
    
    system("pause");
}