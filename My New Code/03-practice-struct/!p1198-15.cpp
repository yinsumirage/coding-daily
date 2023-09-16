#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int N = 2e5 + 5;

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

// 有一个没过 淦 现在我想想写个树状数组把

ll a[N],ans[N<<2],tag[N<<2];
int mod,m,len=0;
char c;
ll x,t=0;

void push_up(int p){
	ans[p]=max(ans[p*2],ans[p*2+1]);
}//	向上维护区间操作 

void f(ll p,ll l,ll r,ll k){
    tag[p]+=k;
    ans[p]+=k;
}

void push_down(ll p,ll l,ll r){
    if(tag[p]==0)return; //无需更新
    ll mid=(l+r)>>1;
    f(p*2,l,mid,tag[p]);
    f(p*2+1,mid+1,r,tag[p]);
    tag[p]=0;
    //向下更新两个儿子
}

void update(ll nl,ll nr,ll l,ll r,ll p,ll k){
    //nl nr 为要修改区间 l r为当前区间
    if(nl<=l&&r<=nr){ //区间包含自己则只改自己
        ans[p]+=k;
        tag[p]+=k;
        return;
    }
    push_down(p,l,r); //向下更新一下
    ll mid=(l+r)>>1;
    if(nl<=mid) update(nl,nr,l,mid,p*2,k);
    if(mid<nr) update(nl,nr,mid+1,r,p*2+1,k);
    push_up(p); //最后向上回溯
}

ll query(ll ql,ll qr,ll l,ll r,ll p){
    ll res=0;
    if(ql<=l&&r<=qr){
        return ans[p];
    }
    ll mid=(l+r)>>1;
    push_down(p,l,r);
    if(ql<=mid)res=max(res,query(ql,qr,l,mid,2*p));
    if(qr>mid)res=max(res,query(ql,qr,mid+1,r,2*p+1));
    return res;
}

int main() {
    m=read();mod=read();
    for(int i=1;i<=m;i++){
        cin>>c;x=read();
        if(c=='Q'){
            t=query(len-x+1,len,1,m,1);
            printf("%lld\n",t);
        }
        else {
            len++;
            int z=x+t;
            while(z<0)z+=mod;
            z%=mod;
            update(len,len,1,m,1,z);
        }
    }
    //system("pause");
}