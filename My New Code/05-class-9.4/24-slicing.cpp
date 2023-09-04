#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 5;

int n;
int h[N],k,sum=0;
int l,r,mid,ans;

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

bool judge(int mid){
    int s=0;
    for(int i=1;i<=n;i++)s+=h[i]/mid;
    if(s>=k)return true;
    else return false;
}

int main(){
    n=read();
    for(int i=1;i<=n;i++)h[i]=read(),sum+=h[i];
    k=read();
    if(sum<k){
        printf("0\n");
        return 0;
    }
    l=0,mid=sum/k;
    r=mid+1;
    while(mid!=l){
        if(judge(mid)){
            l=ans=mid;
            mid=(r+mid)/2;
        }
        else {
            r=mid;
            mid=(r+l)/2;
        }
    }
    printf("%d\n",ans);
    system("pause");
}