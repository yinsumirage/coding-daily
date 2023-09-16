#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=0x3f3f3f3f;
const int N = 1e5 + 5;

int n,m;
bool ji[N];
struct person{
    int l,r;
}p[N];

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
    n=read();
    p[1].l=0;
    p[1].r=0;
    p[0].l=1;
    p[0].r=1;
    for(int i=2;i<=n;i++){
        int k=read(),pr=read();
        if(pr){
            int ri=p[k].r;
            p[i].l=k;
            p[i].r=ri;
            p[k].r=i;
            p[ri].l=i;
        }
        else{
            int le=p[k].l;
            p[i].r=k;
            p[i].l=le;
            p[k].l=i;
            p[le].r=i;
        }
    }
    m=read();
    for(int i=1;i<=m;i++){
        int x=read();
        if(ji[x])continue;
        ji[x]=1;
        int le=p[x].l;
        int ri=p[x].r;
        p[le].r=ri;
        p[ri].l=le;
    }
    int st=0;
    while(1){
        st=p[st].r;
        if(st==0)break;
        printf("%d ",st);
    }
    system("pause");
}