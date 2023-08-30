#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

ll n,k,a[N];
ll qma[N],qmi[N];


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

void min_deque(){
    int hh=1,tt=0; //head严格对应首元素 tail对应尾元素 此时无元素在队列
    for(int i=1;i<=n;i++){
        while(hh<=tt&&qmi[hh]+k<=i)hh++; //首元素已经比现元素i小k了 就踢了
        while(hh<=tt&&a[i]<a[qmi[tt]])tt--; //新元素更小，比尾元素优，踢掉尾元素
        qmi[++tt]=i;
        if(i>=k)printf("%d ",a[qmi[hh]]);
    }
    printf("\n");
}

void max_deque(){
    int hh=1,tt=0;
    for(int i=1;i<=n;i++){
        while(hh<=tt&&qma[hh]+k<=i)hh++;
        while(hh<=tt&&a[i]>a[qma[tt]])tt--;
        qma[++tt]=i;
        if(i>=k)printf("%d ",a[qma[hh]]);
    }
    printf("\n");
}

int main() {
    fastio;
    n=read();
    k=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    min_deque();
    max_deque();
}