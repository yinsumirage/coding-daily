#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 3e5 + 10;

int n,las=0,ans=0;

struct r{
    int s,e;
}arr[N];

bool cmp(r a,r b){
    if(a.e==b.e)return a.s<b.s;
    return a.e<b.e;
}

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

int main(){
    n=read();
    for(int i=1;i<=n;i++){
        arr[i].s=read(),arr[i].e=read();
    }
    sort(arr+1,arr+1+n,cmp);
    for(int i=1;i<=n;i++){
        if(arr[i].s>=las){
            ans++;las=arr[i].e;
            continue;
        }
    }
    printf("%d",ans);
    system("pause");
}