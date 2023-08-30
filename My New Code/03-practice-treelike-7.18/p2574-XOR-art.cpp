#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
const int N = 1e6 + 5;

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

ll n,m,ans[N<<2],tag[N<<2];
string s;

void push_up(int p){
	ans[p]=ans[p*2]+ans[p*2+1];
}//	向上更新标签

void build(ll p,ll l,ll r){
    tag[p]=0;
    if(l==r){
        ans[p]=s[l]-'0';
        return;
    }
    ll mid=(l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    push_up(p);
}

void push_down(ll p,ll l,ll r){ //更新下面的标签
    if(tag[p]==0) return;
    int mid=(l+r)>>1;
    tag[p*2]^=1;
    tag[p*2+1]^=1;
    ans[p*2]=mid-l+1-ans[p*2];
    ans[p*2+1]=r-mid-ans[p*2+1];
    tag[p]=0;
}

void update(ll nl,ll nr,ll l,ll r,ll p){
    if(nl<=l&&r<=nr){
        ans[p]=r-l+1-ans[p];
        tag[p]^=1;
        return;
    }
    push_down(p,l,r);
    ll mid=(l+r)>>1;
    if(nl<=mid) update(nl,nr,l,mid,p*2);
    if(mid<nr) update(nl,nr,mid+1,r,p*2+1);
    push_up(p);
}

ll query(ll ql,ll qr,ll l,ll r,ll p){
    ll res=0;
    if(ql<=l&&r<=qr){
        return ans[p];
    }
    ll mid=(l+r)>>1;
    push_down(p,l,r);
    if(ql<=mid)res+=query(ql,qr,l,mid,2*p);
    if(qr>mid)res+=query(ql,qr,mid+1,r,2*p+1);
    return res;
}

int main() {
    n=read();
    m=read();
    cin>>s;
    s=' '+s;
    build(1,1,n);
    ll x,y;
    for(ll i=0,j;i<m;i++){
        j=read();
        if(j==0){
            x=read();
            y=read();
            update(x,y,1,n,1);
        }
        else {
            x=read();
            y=read();
            printf("%lld\n",query(x,y,1,n,1));
        }
    }
    //system("pause");
    return 0;
}