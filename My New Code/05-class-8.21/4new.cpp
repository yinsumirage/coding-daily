#include<iostream> 
using namespace std; 
typedef long long ll; 
typedef pair<int, int> pii; 
const int N = 1e6 + 5; 
 
int n,h,now,zero[N],las,bian[N]; 
ll sum=0;

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
    n=read();h=read(); 
    for(ll i=1;i<=n;i++){ 
        now=read(); 
        zero[h-now]++; 
        sum-=min(las,now); 
        las=now; 
        if(i==1||i==n){ 
            sum-=now; 
        } 
    } 
    int ji=zero[0]; 
    for(ll i=1;i<=h;i++){ 
        sum+=ji+1; 
        ji+=zero[i]; 
    } 
    printf("%lld\n",sum); 
    //system("pause"); 
} 