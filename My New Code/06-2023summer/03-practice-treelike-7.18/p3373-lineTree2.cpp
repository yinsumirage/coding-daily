#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

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

struct Segment_Tree{
    ll sum,add,mul;
    int l,r;
}ans[N*4];

ll n,q,m,a[N];

void push_up(int p) {
	ans[p].sum=(ans[p*2].sum+ans[p*2+1].sum)%m;
    return;
}

void build(ll p,ll l,ll r){
    ans[p].mul=1;
    ans[p].l=l;
    ans[p].r=r;
    if(l==r){
        ans[p].sum=a[l]%m;
        return;
    }
    ll mid=(l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    push_up(p);
}

void push_downplz(ll p){
    if(ans[p].l==ans[p].r&&ans[p].r==0)return;

    ans[p*2].sum=(ans[p*2].sum*ans[p].mul+ans[p].add*(ans[p*2].r-ans[p*2].l+1))%m;
    ans[p*2+1].sum=(ans[p*2+1].sum*ans[p].mul+ans[p].add*(ans[p*2+1].r-ans[p*2+1].l+1))%m;

    ans[p*2].mul=(ans[p*2].mul*ans[p].mul)%m;
    ans[p*2+1].mul=(ans[p*2+1].mul*ans[p].mul)%m;

    ans[p*2].add=(ans[p*2].add*ans[p].mul+ans[p].add)%m;
    ans[p*2+1].add=(ans[p*2+1].add*ans[p].mul+ans[p].add)%m;
    
    ans[p].add=0;
    ans[p].mul=1;
    return;
}

void update(ll l,ll r,ll p,ll k){
    if(l<=ans[p].l&&ans[p].r<=r){
        ans[p].sum=(ans[p].sum+k*(ans[p].r-ans[p].l+1))%m;
        ans[p].add=(ans[p].add+k)%m;
        return;
    }
    push_downplz(p);
    ll mid=(ans[p].l+ans[p].r)>>1;
    if(l<=mid) update(l,r,p*2,k);
    if(mid<r) update(l,r,p*2+1,k);
    push_up(p);
}

void updateplx(ll l,ll r,ll p,ll k){
    if(l<=ans[p].l&&ans[p].r<=r){
        ans[p].sum=(ans[p].sum*k)%m;
        ans[p].add=(ans[p].add*k)%m;
        ans[p].mul=(ans[p].mul*k)%m;
        return;
    }
    push_downplz(p);
    ll mid=(ans[p].l+ans[p].r)>>1;
    if(l<=mid) updateplx(l,r,p*2,k);
    if(mid<r) updateplx(l,r,p*2+1,k);
    push_up(p);
}

ll query(ll x,ll y,ll p){
    ll res=0;
    if(x<=ans[p].l&&ans[p].r<=y){
        return ans[p].sum;
    }
    push_downplz(p);
    ll mid=(ans[p].l+ans[p].r)>>1;
    if(x<=mid)res=(res+query(x,y,2*p))%m;
    if(y>mid)res=(res+query(x,y,2*p+1))%m;
    return res;
}

int main() {
    n=read();
    q=read();
    m=read();
    for(ll i=1;i<=n;i++){
        a[i]=read();
    }
    build(1,1,n);
    ll x,y,k;
    for(ll i=0,j;i<q;i++){
        j=read();
        x=read();
        y=read();
        if(j==1){
            k=read();
            updateplx(x,y,1,k);
        }
        else if(j==2){
            k=read();
            update(x,y,1,k);
        }
        else{
            printf("%lld\n",query(x,y,1)%m);
        }
    }
    //system("pause");
    return 0;
}