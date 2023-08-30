#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

int n,m,tree[N];
int ans=0x3f3f3f3f;

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

// 这个是单点修改 + 区间查询

int lowbit(int k){ // 留下最低位的1
    return k& -k;
}

void add(int x,int k){ //单点修改
    while(x<=n){
        tree[x]+=k;
        x+=lowbit(x);
    }
} // 改变x的值，就要加上自己的lowbit，一直加到n，这些节点都加

int sum(int x){
    int ans=0;
    while(x!=0){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}

signed main() {
    //fastio;
    n=read();
    m=read();
    for(int i=1;i<=n;i++){
        int a;
        a=read();
        add(i,a);
    }
    for(int i=1;i<=m;i++){
        int a,b,c;
        a=read(),b=read(),c=read();
        if(a==1)add(b,c);
        if(a==2)printf("%d\n",sum(c)-sum(b-1));
    }

    system("pause");
}