#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll; 
typedef unsigned long long ull; 
const int N = 4e5 + 5; 
 
int n,ni=1;
ll ans=0; 
ll a[N]={0}; 
ll tree[N]={0}; 
int lisan[N]={0}; 
 
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
 
struct node{ 
    ll val,num; 
}dian[N]; 
 
ll lowbit(int k){return k&-k;} 
void add(ll x,int k){ 
    while(x<=n){ 
        tree[x]+=k; 
        x+=lowbit(x); 
    } 
} 
ll sum(ll x){ 
    ll ans=0; 
    while(x!=0){ 
        ans+=tree[x];x-=lowbit(x); 
    } 
    return ans; 
} 
bool cmp(node a,node b){ 
    if(a.val==b.val)return a.num<b.num;
    return a.val<b.val; 
}
 
int main(){ 
    n=read(); 
    for(int i=1;i<=n;i++){ 
        dian[i].val=read(); 
        dian[i].num=i; 
    } 
    sort(dian+1,dian+n+1,cmp); 
    lisan[dian[1].num]=1; 
    for(int i=2;i<=n;i++){ 
        if(dian[i].val>dian[i-1].val)ni++; 
        lisan[dian[i].num]=ni; //对原来的数字进行牌序
    } 
    for(int i=1;i<=n;i++){ 
        add(lisan[i],1); 
        ans+=i-sum(lisan[i]); 
    } 
    printf("%lld\n",ans); 
    system("pause"); 
}  
