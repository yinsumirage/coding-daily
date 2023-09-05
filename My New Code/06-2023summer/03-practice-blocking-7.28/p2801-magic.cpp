#include<bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

int n,q,h[N],d[N],belong[N],L[N],R[N],lazy[N];
int block,tot;
int ans;
char c;

inline ll read(){
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

void fr(char &c){
    c=0;while(c!='M'&&c!='A')c=getchar();
}

void build(){
    block=sqrt(n);tot=n/block;
    if(n%block)tot++;
    for(int i=1;i<=n;i++){
        belong[i]=(i-1)/block+1;
        d[i]=h[i];
    }
    for(int i=1;i<=tot;i++){
        L[i]=(i-1)*block+1;
        R[i]=i*block;
    }
    R[tot]=n;
    for(int i=1;i<=tot;i++){
        sort(d+L[i],d+R[i]+1);
    }
}

void change(int x,int y,int k){
    if(belong[x]==belong[y]){
        for(int i=x;i<=y;i++){
            h[i]+=k;
        }
        for(int i=L[belong[x]];i<=R[belong[x]];i++){
            d[i]=h[i];
        }
        sort(d+L[belong[x]],d+R[belong[x]]+1);
    }
    else {
        for(int i=x;i<=R[belong[x]];i++){
            h[i]+=k;
        }
        for(int i=L[belong[x]];i<=R[belong[x]];i++){
            d[i]=h[i];
        }
        sort(d+L[belong[x]],d+R[belong[x]]+1);
        for(int i=L[belong[y]];i<=y;i++){
            h[i]+=k;
        }
        for(int i=L[belong[y]];i<=R[belong[y]];i++){
            d[i]=h[i];
        }
        sort(d+L[belong[y]],d+R[belong[y]]+1);
        for(int i=belong[x]+1;i<=belong[y]-1;i++){
            lazy[i]+=k;
        }
    }
}

void query(int x,int y,int k){
    ans=0;
    if(belong[x]==belong[y]){
        for(int i=x;i<=y;i++){
            if(lazy[belong[x]]+h[i]>=k)ans++;
        }
        printf("%d\n",ans);
    }
    else {
        for(int i=x;i<=R[belong[x]];i++){
            if(lazy[belong[x]]+h[i]>=k)ans++;
        }
        for(int i=L[belong[y]];i<=y;i++){
            if(lazy[belong[y]]+h[i]>=k)ans++;
        }
        for(int i=belong[x]+1;i<=belong[y]-1;i++){
            int ll=L[i],rr=R[i],tmp=0,mid;
            while(ll<=rr){
                mid=(ll+rr)>>1;
                if(d[mid]+lazy[i]>=k){
                    rr=mid-1,tmp=R[i]-mid+1;
                }
                else {
                    ll=mid+1;
                }
            }
            ans+=tmp;
        }
        printf("%d\n",ans);
    }
}

signed main() {
    fastio;
    n=read();q=read();
    for(int i=1;i<=n;i++)h[i]=read();
    build();
    while(q--){
        fr(c);
        int x=read(),y=read(),k=read();
        if(c=='M')change(x,y,k);
        else if(c=='A')query(x,y,k);
    }
    system("pause");
}